/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:37:27 by tsankola          #+#    #+#             */
/*   Updated: 2023/03/24 13:52:06 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ring.h"
#include <stdlib.h>

// Swaps the position of the first two elements of stack
void	ps_swap(t_ring **ring)
{
	void	*value;

	if (*ring == NULL)
		return ;
	value = ring_take(ring);
	ring_reverse_rotate(ring);
	ring_add(ring, value);
	ring_rotate(ring);
}

// Pushes the first element from ring_a to ring_b. If a is empty, nothing
// happens.
void	ps_push(t_ring **ring_a, t_ring **ring_b)
{
	if (*ring_a == NULL)
		return ;
	ring_add(ring_b, ring_take(ring_a));
}

// Rotates the ring so that the first element becomes the last
void	ps_rotate(t_ring **ring)
{
	if (*ring != NULL)
		*ring = (*ring)->prev;
}

// Rotates the ring so that the last element becomes the first
void	ps_reverse_rotate(t_ring **ring)
{
	if (*ring != NULL)
		*ring = (*ring)->next;
}
