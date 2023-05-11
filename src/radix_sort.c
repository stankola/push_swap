/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:27:56 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 13:27:57 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "push_swap_operations.h"
#include "stack.h"
#include "ring.h"
#include "sorting_algorithms.h"
#include "libft.h" // TEST
#include <stdio.h> // TEST

// Sort 0's right and 1's left (smaller ones right, bigger ones left)
// executes size actions
// complexity: O(n)
// Optimized with the knowledge that we have at max size / 2 (+ 1?) values to
// move. The impact is veeeeery slight. If the last number is odd, then there
// is no impact.
static void	base_step(t_ring *rings[], t_stack *commands, unsigned int size)
{
	unsigned int	radix;
	unsigned int	i;
	unsigned int	push_count;

	i = 0;
	radix = 1;
	push_count = 0;
	while (i++ < size && push_count < (size / 2) + (size % 2))
	{
		if (!(*(int *)rings[a]->content & radix))
		{
			execute(rings, commands, ps_pb, 1);
			push_count++;
		}
		else
			execute(rings, commands, ps_ra, 1);
	}
}

// Sorting, theoretically executes min size, max 2 * size actions.
// In practice, will execute 3/2 * size actions.
// Complexity: O(n)
// Implements optimization in combining some rotations. Not very effective:
// For 100 numbers the impact was 2 moves, ugh...
// This could be optimized using the knowledge that we have at max
// size / 2 (+ 1?) values to move
// Another improvement would be to peek inside the ring and rotate in the
// direction of the closest value to push
static void	sorting_step(t_ring *rings[], t_stack *commands, unsigned int radix)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	push_a_count;
	unsigned int	push_b_count;

	push_a_count = 0;
	push_b_count = 0;
	i = 0;
	i = get_ring_size(rings[a]);
	j = get_ring_size(rings[b]);
	while (i-- > 0)
	{
		if (!(*(int *)rings[a]->content & radix))
		{
			execute(rings, commands, ps_pb, 1);
			push_a_count++;
		}
		else if ((i == 0) && push_a_count > 0)
		{
			execute(rings, commands, ps_rr, 1);
			push_a_count--;
		}
		else
			execute(rings, commands, ps_ra, 1);
	}
	execute(rings, commands, ps_rb, push_a_count);
	while (j-- > 0)
	{
		if (*(int *)rings[b]->content & radix)
		{
			execute(rings, commands, ps_pa, 1);
			push_b_count++;							// Not actually used
		}
		else
			execute(rings, commands, ps_rb, 1);
	}
}

// Executes size / 2 actions
// Complexity O(n)
static void	final_step(t_ring *rings[], t_stack *commands)
{
	unsigned int	i;

	i = get_ring_size(rings[b]);
	execute(rings, commands, ps_pa, i);
}

// For positive values, assuming normalized values (ie. 0,1,2,3,4,5,6...)
t_stack	*radix_sort(t_ring *rings[], unsigned int size)
{
	t_stack			*commands;
	unsigned int	radix;

	if (rings == NULL)
		return (NULL);
	commands = ft_new_stack();
	if (commands == NULL)
		return (NULL);
	if (! (is_sorted(rings[a])))
	{
		base_step(rings, commands, size);
		radix = 2;
		while (radix < size)
		{
			sorting_step(rings, commands, radix);
			radix <<= 1;
		}
		final_step(rings, commands);
	}
	return (commands);
}
