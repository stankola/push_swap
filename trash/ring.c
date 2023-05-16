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
#include "libft.h"

// Adds content to the front of the ring or creates a new ring if NULL is passed
// as the first argument
void	ring_add(t_ring **ring, void *content)
{
	t_ring	*newring;

	newring = malloc(sizeof(t_ring));
	if (newring == NULL)
		return ;
	newring->next = newring;
	newring->prev = newring;
	newring->content = content;
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

	ft_printf("Taking %p prev %p next %p\n prev next %p next prev %p next next %p prev prev %p\n", *ring, (*ring)->prev, (*ring)->next, (*ring)->prev->next, (*ring)->next->prev, (*ring)->next->next, (*ring)->prev->prev);
	if (ring == NULL || *ring == NULL)
		return (NULL);
	content = (*ring)->content;
	temp_ring = *ring;
	if ((*ring)->next == *ring)
	{
		ft_printf(" final ring\n");
		(*ring)->next = NULL;
		ft_printf("Ok?");
		ft_printf("%p", *ring);
		(*ring)->prev = NULL;
		free(*ring);
		*ring = NULL;
	}
	else
	{
		ft_printf("not final ring\n");
		ft_printf("%d %p prev %p next %p\n prev next %p next prev %p\n", *(int*)(*ring)->content, *ring, (*ring)->prev, (*ring)->next, (*ring)->prev->next, (*ring)->next->prev);
		t_ring	*next;
		t_ring	*prev;
		next = (*ring)->next;
		prev = (*ring)->prev;
		(*ring)->next = NULL;
		(*ring)->prev = NULL;
		ft_printf("-- %p %p --\n", next, prev);
		next->prev = prev;
		prev->next = next;
		ft_printf("%p %p %p %p %p %p\n", next, prev, next->prev, prev->next, next->next, prev->prev);
//		ft_printf("%d %p prev %p next %p\n ", *(int*)(*ring)->content, *ring, (*ring)->prev, (*ring)->next);
		temp_ring = *ring;
		*ring = prev;
//		ft_printf("%p prev %p next %p\n prev next %p next prev %p\n", *ring, (*ring)->prev, (*ring)->next, (*ring)->prev->next, (*ring)->next->prev);

//		ft_printf("prev %p\n", (*ring)->prev);
//		ft_printf("next %p\n", (*ring)->next);
		free(temp_ring);
//		(*ring)->next = temp_ring->next;
//		(*ring)->next->prev = *ring;
//		(*ring)->next = NULL;
//		(*ring)->prev = NULL;
//		*ring = (*ring)->prev;
	}
//	temp_ring->next = NULL;
//	temp_ring->prev = NULL;
//	free(temp_ring);
	if (*ring != NULL)
	{
		ft_printf("Ring after take %p next %p prev %p\n", *ring, (*ring)->next, (*ring)->prev);
		ft_printf("next prev %p next next %p prev next %p prev prev %p\n", (*ring)->next->prev, (*ring)->next->next, (*ring)->prev->next, (*ring)->prev->prev);
	}
	ft_printf("Returning %d\n", *(int*)content);
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

void	ring_del(t_ring **ring, void (*del)(void*))
{
	void	*content;

//	ft_printf("joojoo");
	if (*ring == NULL)
		return ;
//	ft_printf("ring %p prev %p next %p\n", *ring, (*ring)->prev, (*ring)->next);
	content = ring_take(ring);
//	ft_printf("%d\n", *(int*)content);
	if (del != NULL)
		(del)(content);
//	ft_printf("jEEjaa");
	if (*ring != NULL)
		ring_del(ring, del);
//	ft_printf("jEEjEE");
}
