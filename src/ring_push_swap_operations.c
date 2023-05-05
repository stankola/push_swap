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
#include <stdio.h> // TEST
#include "push_swap.h" // TEST

// Swaps the position of the first two elements of stack
void	ring_ps_swap(t_ring **ring)
{
	void	*value;

	if (*ring == NULL)
		return ;
	value = ring_take(ring);
	ring_rotate(ring);
	ring_add(ring, value);
	ring_reverse_rotate(ring);
}

// Pushes the first element from stack_a to stack_b. If a is empty, nothing happens.
void	ring_ps_push(t_ring **ring_a, t_ring **ring_b)
{
	if (*ring_a == NULL)
		return ;
	ring_add(ring_b, ring_take(ring_a));
}

// Rotates the stack so that the first element becomes the last
void	ring_ps_rotate(t_ring **ring)
{
	if (*ring != NULL)
		*ring = (*ring)->prev;
}

// Rotates the stack so that the last element becomes the first
void	ring_ps_reverse_rotate(t_ring **ring)
{
	if (*ring != NULL)
		*ring = (*ring)->next;
}
/*
int main(void)	//TEST
{
	t_ring *ringu;
	t_ring *ringu2;
	int taulu[] = {1,2,3,4,5};

	ring_add(&ringu, &taulu[1]);
	ring_add(&ringu, &taulu[2]);
	ring_add(&ringu, &taulu[2]);
	ring_add(&ringu, &taulu[4]);
	ring_add(&ringu, &taulu[3]);
	ringu2 = NULL;

	t_ring **rings = malloc(sizeof(t_ring) * 2);
	rings[a] = ringu;
	rings[b] = ringu2;

	fprintf(stderr, "%p %p\n", rings[a], rings[b]);
	print_rings(rings);
	ring_ps_push(&rings[a], &rings[b]);
	printf("push: %d %d\n", *(int*)rings[a]->content, *(int*)rings[b]->content);
	ring_ps_swap(&rings[a]);
	ring_ps_swap(&rings[b]);
	printf("swap: %d %d\n", *(int*)rings[a]->content, *(int*)rings[b]->content);
	ring_ps_rotate(&rings[a]);
	ring_ps_rotate(&rings[b]);
	printf("rotate: %d %d\n", *(int*)rings[a]->content, *(int*)rings[b]->content);
	ring_ps_reverse_rotate(&rings[a]);
	ring_ps_reverse_rotate(&rings[b]);
	printf("reverse rotate: %d %d\n", *(int*)rings[a]->content, *(int*)rings[b]->content);
	print_rings(rings);
	ring_ps_push(&rings[a], &rings[b]);
	ring_ps_push(&rings[a], &rings[b]);
	ring_ps_push(&rings[a], &rings[b]);
	ring_ps_push(&rings[a], &rings[b]);
	print_rings(rings);
	ring_ps_push(&rings[a], &rings[b]);
	fprintf(stderr, "%p %p\n", rings[a], rings[b]);
	print_rings(rings);
}*/