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
#include "test_utils.h"

static int	get_distance_to_closest(t_ring *ring, int radix)
{
	t_ring	*clockwise;
	t_ring	*cclockwise;
	int		distance;

	distance = 0;
	if (! (*(int *)ring->content & radix))
		return (distance);
	clockwise = ring->prev;
	cclockwise = ring;
	distance = 1;
	while (clockwise != cclockwise)
	{
		if (! (*(int *)clockwise->content & radix) || ! (*(int *)cclockwise->content & radix))
			return (distance);
		if (distance < 0)
		{
			clockwise = clockwise->prev;
			distance = distance * (-1) + 1;
//			ft_printf("Moving to %d distance %d\n", *(int *)clockwise->content, distance);
		}
		else
		{
			cclockwise = cclockwise->next;
			distance = distance * (-1);
//			ft_printf("Moving to %d distance %d\n", *(int *)cclockwise->content, distance);
		}
	}
	return (INT32_MIN);
}

// Sort 0's right and 1's left (smaller ones right, bigger ones left)
// executes size actions
// complexity: O(n)
// Optimized with the knowledge that we have at max size / 2 (+ 1?) values to
// move. The impact is veeeeery slight. If the last number is odd, then there
// is no impact.
// Could be optimized by rotating to the direction of the closest odd number
/*
static void	base_step(t_ring *rings[], t_stack *commands, unsigned int size, unsigned int radix)
{
	unsigned int	push_count;
	int				distance;

	push_count = 0;
	while (push_count < (size / 2) + (size % 2))
	{
		if (!(*(int *)rings[a]->content & radix))
		{
			execute(rings, commands, ps_pb, 1);
			push_count++;
		}
		else
		{
			distance = get_distance_to_closest(rings[a], radix);
//			ft_printf("Got distance %d\n", distance);
			if (distance > 0)
				execute(rings, commands, ps_ra, distance);
			if (distance < 0)
				execute(rings, commands, ps_rra, -distance);
			execute(rings, commands, ps_pb, 1);
			push_count++;
			if (*(int *)rings[b] % 2 == 1)
			{
				print_rings(rings);
				getchar();

			}
		}
	}
}
*/

static void	base_step(t_ring *rings[], t_stack *commands, unsigned int size, unsigned int radix)
{
	unsigned int	i;
	unsigned int	push_count;

	i = 0;
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
	i = ring_get_size(rings[a]);
	j = ring_get_size(rings[b]);
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

	i = ring_get_size(rings[b]);
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
	if (1) //! (is_sorted(rings[a])))
	{
		radix = 1;
		while (radix << 1 <= size)
			radix <<= 1;
		base_step(rings, commands, size, radix);
		ft_printf("BASED\n");
		while (radix > 0)
		{
			radix >>= 1;
			sorting_step(rings, commands, radix);
		}
		final_step(rings, commands);
	}
	if (! is_sorted(rings[a]))
	{
		print_rings(rings);
		ft_printf("Not sorted\n");
		getchar();
	}
	return (commands);
}
