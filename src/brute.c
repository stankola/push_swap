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

typedef struct	s_ring_state
{
	t_ring				**rings;
	struct s_ring_state	*parent;
	int					visited;
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
t_stack	*brute(t_ring *rings[])
{
	t_ring_state	*current_state;
	int				command;
	t_ring_state	*temp_state;
	t_queue			**queues;
	t_stack			*commands;

	if (is_sorted(rings[a]))
		return (NULL);
	queues = ft_calloc(2, sizeof(t_queue *));
	current_state = new_state(clone_rings(rings), NULL, -1);
	if (current_state == NULL)
		return (NULL);
	ft_enqueue(&queues[0], current_state);
	while (1)
	{
		current_state = (t_ring_state *)ft_dequeue(&queues[0]);
		if (current_state->rings[b] == NULL && is_sorted(current_state->rings[a]))
			break ;
		ft_enqueue(&queues[1], current_state);
		command = ps_sa;
		while (command <= ps_rrr)
		{
			temp_state =  new_state(clone_rings(current_state->rings), current_state, command);
			execute(temp_state->rings, NULL, command, 1);
			if (contains(queues[0], temp_state) || contains(queues[1], temp_state))
				ring_state_del(temp_state);
			else
				ft_enqueue(&queues[0], temp_state);
			command++;
		}
	}
	commands = get_command_stack(current_state);
	ft_queueclear(&queues[1], (void (*)(void *))ring_state_del);
	ft_queueclear(&queues[0], (void (*)(void *))ring_state_del);
	free(queues);
	return (commands);
}
