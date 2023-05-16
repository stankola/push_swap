#include "sorting_algorithms.h"
#include "ring.h"
#include "push_swap_operations.h"
#include <stdlib.h>

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
t_ring_state	*new_state(t_ring *rings[], t_ring_state *parent, int prev_cmd)
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
	newstate->prev_command = prev_cmd;
	return (newstate);
}

static int	iptr_eq(int *x, int *y)
{
	return (*x == *y);
}

int	ring_state_eq(t_ring_state *state_a, t_ring_state *state_b)
{
	if (ring_is_equal(state_a->rings[a], state_b->rings[a],
		(int (*)(void *, void *))&iptr_eq)
		&& ring_is_equal(state_a->rings[b], state_b->rings[b],
		(int (*)(void *, void *))&iptr_eq))
		return (1);
	return (0);
}