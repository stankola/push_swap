/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:36:55 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/15 19:37:02 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "push_swap_operations.h"
#include "ring.h"
#include "stack.h"
#include "ft_queue.h"
#include "sorting_algorithms.h"
#include "test_utils.h"
#include <stdio.h> // TEST
//#define stderr 2

typedef struct	s_ring_state
{
	t_ring				**rings;
	struct s_ring_state	*parent;
	int					visited;
	int					heuristic_value;
	int					path_length;
	int					prev_command;
}				t_ring_state;

void	ring_state_del(t_ring_state *ring_state)
{
	if (ring_state == NULL)
		return ;
	ring_del(&(ring_state->rings[a]), NULL);
	ring_del(&(ring_state->rings[b]), NULL);
	free(ring_state->rings);
	ring_state->rings = NULL;
	ring_state->parent = NULL;
	free(ring_state);
}

t_ring_state	*new_state(t_ring *rings[], t_ring_state *parent, int prev_command)
{
	t_ring_state	*newstate;

	newstate = malloc(sizeof(t_ring_state));
	if (newstate == NULL)
		return (NULL);
	newstate->rings = rings;
	newstate->parent = parent;
	if (parent != NULL)
		newstate->path_length = parent->path_length + 1;
	else
		newstate->path_length = 0;
	newstate->heuristic_value = calculate_heuristic(rings, newstate->path_length);
	newstate->visited = 0;
	newstate->prev_command = prev_command;
	return (newstate);
}

t_ring	**clone_rings(t_ring *rings[])
{
	t_ring	**clones;

	clones = malloc(sizeof(t_ring *) * (b + 1));
	if (clones == NULL)
		return (NULL);
	clones[a] = ring_clone(rings[a]);
	clones[b] = ring_clone(rings[b]);
	return (clones);
}

int	iptr_equality_comparator(int *x, int *y)
{
	return (*x == *y);
}

int	ring_state_equality_comparison(t_ring_state *state_a, t_ring_state *state_b)
{
	if (ring_is_equal(state_a->rings[a], state_b->rings[a], (int (*)(void *, void *))&iptr_equality_comparator)
		&& ring_is_equal(state_a->rings[b], state_b->rings[b], (int (*)(void *, void *))&iptr_equality_comparator))
		return (1);
	return (0);

}

t_stack	*get_command_stack(t_ring_state *state)
{
	t_stack	*commands;
	t_stack	*temp_stack;
	int		*iptr;

	if (state == NULL)
		return (NULL);
	commands = ft_new_stack();
	temp_stack = ft_new_stack();
	while (state->parent != NULL)
	{
		iptr = malloc(sizeof(int));
		*iptr = state->prev_command;
		ft_push(temp_stack, iptr);
		state = state->parent;
	}
	stack_to_stack(temp_stack, commands);
	ft_del_stack(&temp_stack, NULL);
	return (commands);
}

int	contains(t_queue *q, t_ring_state *state)
{
	t_list	*iterator;

	if (q == NULL)
		return (0);
	iterator = q->head;
	while (iterator != NULL)
	{
		if (ring_state_equality_comparison(((t_ring_state *)iterator->content), state))
			return (1);
		iterator = iterator->next;
	}	
	return (0);
}

// search space = (n + 1) * n!
// Best first search
t_stack	*brute(t_ring *rings[], int size)
{
	t_ring_state	*current_state;
	t_ring			**cloned_rings;
	int				command;
	t_ring_state	*temp_state;
	t_queue			*q;			// unexplored
	t_queue			*v;			// explored
	t_stack			*commands;
	int 			debug_i;

	if (is_sorted(rings[a]))
		return (NULL);
	q = NULL;
	v = NULL;
	size += 0;
	cloned_rings = clone_rings(rings);
	current_state = new_state(cloned_rings, NULL, -1);
	if (current_state == NULL)
		return (NULL);
	ft_enqueue(&q, current_state);
	int level = -1;
	while (1)
	{
		current_state = (t_ring_state *)ft_dequeue(&q);
		ft_enqueue(&v, current_state);
		if (current_state->path_length > level)
		{
			ft_printf("level %d\n", level);
			if (q != NULL)
				ft_printf("queue size %d\n", ft_lstsize(q->head));
			if (v != NULL)
				ft_printf("visited size %d\n", ft_lstsize(v->head));
			level = current_state->path_length;
		}
		if (current_state->rings[b] == NULL && is_sorted(current_state->rings[a]))
			break ;
		command = ps_sa;
		debug_i = 0;
		while (command <= ps_rrr)
		{
			cloned_rings = clone_rings(current_state->rings);
			execute(cloned_rings, NULL, command, 1);
			temp_state =  new_state(cloned_rings, current_state, command);
			if (contains(q, temp_state) || contains(v, temp_state))
			{
				ring_state_del(temp_state);
				debug_i++;
			}
			else
				ft_enqueue(&q, temp_state);
			command++;
		}
//		ft_printf("%d states skipped\n", debug_i);
//		getchar();

	}
//	print_rings(current_state->rings);
	commands = get_command_stack(current_state);
	ft_queueclear(&v, (void (*)(void *))ring_state_del);
	ft_queueclear(&q, (void (*)(void *))ring_state_del);
	return (commands);
}
