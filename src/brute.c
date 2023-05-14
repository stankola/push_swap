#include "push_swap.h"
#include "push_swap_operations.h"
#include "ring.h"
#include "stack.h"
#include "ft_queue.h"
#include "sorting_algorithms.h"
#include "test_utils.h"

typedef struct	s_ring_state
{
	t_ring			**rings;
	t_ring_state	*parent;
	int				visited;
	int				heuristic_value;
	int				path_length;
	unsigned int	prev_command;
}				t_ring_state;

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

static int	calculate_heuristic(t_ring *rings[])
{
	int	value;

	value = count_inversions(rings[a], ring_get_size(rings[a]), a);
	value += count_inversions(rings[b], ring_get_size(rings[b]), b);
	value += ring_get_size(rings[b]);
	return (value);
}

t_ring_state	*get_state(t_ring *rings[], t_ring_state *parent, unsigned int prev_command)
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
		newstate->path_length = parent->path_length;
	else
		newstate->path_length = 0;
	newstate->heuristic_value = calculate_heuristic(rings);
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

int	compare_rings(t_ring_state *state_a, t_ring_state *state_b)
{
	//TODO: Functionality
	return (0);
}

//quick and dirty: Editing queue data structure directly
void	ordered_by_heuristic_insert(t_queue *q, t_ring_state *new_state)
{
	// Continue here: add ordered insert. 
	// I think I can cut corners and edit the queue data structure directly
	// instead of adding an ordered insert function....
	// Should check for duplicate states at the same time.

	t_list	*iterator;
	t_list	*prev_position;
	t_list	*position;

	iterator = q->head;
	while (iterator != NULL)
	{
		if (compare_rings(new_state, (t_ring_state *)iterator->content))
		{
			if (new_state->heuristic_value < (t_ring_state *)iterator->content)
				//TODO: Delete old node
			else
				return ;
		}
		// find n such that n->heuristic_value > new_state->heuristic_value save
		// position. Then continue and search for identical state. If found,
		// return. If not found insert new_state to saved position.
		if (new_state->heuristic_value > ((t_ring_state *)iterator->next->content)->heuristic_value)
			position = iterator;	// Rethink, probably needs prev_position too
		else
			iterator = iterator->next;
	}
}

// search space = (n + 1) * n!
// Best first search
t_stack	*brute(t_ring *rings[], int size)
{
	t_stack			*commands;
	t_queue			*q;
	t_ring_state	*current_state;
	t_ring			**cloned_rings;
	int				command;

	if (is_sorted(rings[a]))
		return (NULL);
	commands = NULL;
	q = NULL;
	current_state = get_state(rings, NULL, -1);
	if (current_state == NULL)
		return (NULL);
	ft_enqueue(q, (void *)current_state);
	while (current_state->heuristic_value != 0)
	{
		command = ps_sa;
		// get and enqueue children
		while (command <= ps_rrr)
		{
			cloned_rings = clone_rings(current_state->rings);
			execute(cloned_rings, NULL, command, 1);
			// NEXT: insert cloned ring into an ordered queue q
			command++;
		}
		current_state->visited = 1;
		// current_state = child with lowest heuristic value
	}
	// get path from current_state to root and return it.
	return (NULL);
}