/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:22:16 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 13:22:18 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ring.h"
#include <stdlib.h>

t_ring	*ring_new(void *content)
{
	t_ring	*ring;

	ring = malloc(sizeof(t_ring));
	if (ring == NULL)
		return (NULL);
	ring->next = ring;
	ring->prev = ring;
	ring->content = content;
	return (ring);
}

// Adds content to the front of the ring
void	ring_add(t_ring **ring, void *content)
{
	t_ring	*newring;

	newring = ring_new(content);
	if (*ring != NULL)
	{
		newring->next = (*ring)->next;
		newring->prev = *ring;
		newring->prev->next = newring;
		newring->next->prev = newring;
	}
	*ring = newring;
}

void	*ring_take(t_ring **ring)
{
	void	*content;
	t_ring	*temp_ring;

	if (ring == NULL || *ring == NULL)
		return (NULL);
	temp_ring = (*ring);
	if ((*ring)->next == *ring)
		*ring = NULL;
	else
	{
		*ring = (*ring)->prev;
		(*ring)->next = temp_ring->next;
		(*ring)->next->prev = *ring;
	}
	temp_ring->next = NULL;
	temp_ring->prev = NULL;
	content = temp_ring->content;
	free(temp_ring);
	return (content);
}

void	ring_rotate(t_ring **ring)
{
	if (*ring != NULL)
		*ring = (*ring)->next;
}

void	ring_reverse_rotate(t_ring **ring)
{
	if (*ring != NULL)
		*ring = (*ring)->prev;
}
