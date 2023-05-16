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
#define stderr 2

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

// Simply calculates inversions of a given ring element up to depth length.
// This covers the swap commands, but rotations should be taken into account,
// as well as pushes.
static int	count_inversion(t_ring *ring, int depth, int direction)
{
	int	value;
	int	i;
	int	inversions;

	value = *(int *)ring->content;
	inversions = 0;
	i = 0;
	while (i < depth)
	{
		ring = ring->prev;
		if (direction == a && value > *(int *)ring->content)
			inversions++;
		else if (direction == b && value < *(int *)ring->content)
			inversions++;
		i++;
	}
	return (inversions);
}

// direction == a for ascending, direction == b for descending (or vice versa)
// Complexity O(n^2). Efficiency could be further improved by divide-and-conquer
// approach
static int	count_inversions(t_ring *ring, int size, int direction)
{
	int	count;

	if (ring == NULL)
		return (0);
	count = 0;
	while (size > 0)
	{
		count += count_inversion(ring, size - 1, direction);
		size--;
		ring = ring->prev;
	}
	return (count);
}

static int	calculate_heuristic(t_ring *rings[], int length_to_root)
{
	int	value;

	value = count_inversions(rings[a], ring_get_size(rings[a]), a);
	value += count_inversions(rings[b], ring_get_size(rings[b]), b);
	value += ring_get_size(rings[b]);
	value += length_to_root;
	return (value);
}

t_ring_state	*new_state(t_ring *rings[], t_ring_state *parent, int prev_command)
{
	t_ring_state	*newstate;

	newstate = malloc(sizeof(t_ring_state));
	if (newstate == NULL)
		return (NULL);
	newstate->rings = malloc(sizeof(t_ring) * b);
	if (newstate->rings == NULL)
		return (NULL);
	newstate->rings[a] = rings[a];
	newstate->rings[b] = rings[b];
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

	clones = malloc(sizeof(t_ring) * b);
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

/* Looks for the correct position in q for the new_state. At the same time,
 * checks for t_ring_states that have identical rings. Once the correct position
 * is found, continues the search until the end (or start) of q. If an identical
 * new_state is found, checks if it has greater heuristic_value. If it does
 * deletes the old ring_state.
 */
void	insert_ordered_by_heuristic(t_ring **q, t_ring_state *new_state)
{
	t_ring			*iterator;
	t_ring_state	*temp_state;
	t_ring			*insert_position;

	if (*q == NULL)
	{
		ring_add(q, new_state);
		return ;
	}
	ft_printf("Got\n");
	print_rings(new_state->rings);
	
	iterator = *q;
	ring_reverse_rotate(&iterator);
	insert_position = NULL;
	do						// Illegal
	{
		if (ring_state_equality_comparison(new_state, (t_ring_state *)iterator->content))
		{
			if ((new_state->heuristic_value < ((t_ring_state *)iterator->content)->heuristic_value))
				{
					temp_state = (t_ring_state *)ring_take(&iterator);
					ring_state_del(temp_state);
				}
			else
			{
				ring_state_del(new_state);
				return ;		// free new_state???
			}
		}
		ft_printf("Heueh new %d cur %d\n", new_state->heuristic_value, ((t_ring_state *)iterator->next->content)->heuristic_value);
		if (! insert_position && new_state->heuristic_value <= ((t_ring_state *)iterator->next->content)->heuristic_value)
			insert_position = iterator->next;
		ring_reverse_rotate(&iterator);
	} 	while (iterator != *q);
	if (insert_position)
	{
		ft_printf("Insertion!!!");
		ring_add(&insert_position, new_state);
	}
}

t_ring_state	*get_next_unvisited_state(t_ring *queue)
{
	t_ring	*iterator;

	if (queue == NULL)
		return (NULL);
	iterator = queue;
	if (! ((t_ring_state *)iterator->content)->visited)
		return ((t_ring_state *)iterator->content);
	while (iterator->prev != queue)
	{
		if (! ((t_ring_state *)iterator->content)->visited)
			return ((t_ring_state *)iterator->content);
		ring_reverse_rotate(&iterator);
	}
	return (NULL);
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
	t_queue			*v;			// explored, not really used
	t_stack			*commands;

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
			level = current_state->path_length;
		}
		if (current_state->rings[b] == NULL && is_sorted(current_state->rings[a]))
			break ;
		command = ps_sa;
		while (command <= ps_rrr)
		{
			cloned_rings = clone_rings(current_state->rings);
			execute(cloned_rings, NULL, command, 1);
			temp_state =  new_state(cloned_rings, current_state, command);
			if (contains(v, temp_state))
				ring_state_del(temp_state);
			else
				ft_enqueue(&q, temp_state);
			command++;
		}
	}
//	print_rings(current_state->rings);
	commands = get_command_stack(current_state);
	ft_queueclear(&v, (void (*)(void *))ring_state_del);
	ft_queueclear(&q, (void (*)(void *))ring_state_del);
	return (commands);
}
