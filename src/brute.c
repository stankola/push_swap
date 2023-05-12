#include "push_swap.h"
#include "push_swap_operations.h"
#include "ring.h"
#include "stack.h"
#include "ft_queue.h"
#include "sorting_algorithms.h"

int	count_inversion(t_ring *ring, int depth)
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
		if (value > *(int *)ring->content)
			inversions++;
		i++;
	}
	return (inversions);
}

int	count_inversions(t_ring *ring, int size)
{
	int	count;

	count = 0;
	while (size > 0)
	{
		count += count_inversion(ring, size - 1);
		size--;
	}
	return (count);
}

t_stack	*brute(t_ring *rings[], int size)
{
	t_stack	*commands;
	t_queue	*q;

	if (is_sorted(rings[a]))
		return ;
	q = NULL;
}