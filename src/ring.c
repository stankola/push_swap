#include "ring.h"

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

void	ring_add(t_ring **ring, void *content)
{
	t_ring	*newring;

	newring = ring_new(content);
	newring->next = *ring;
	newring->prev = (*ring)->prev;
	(*ring)->prev->next = newring;
	(*ring)->prev = newring;
	*ring = newring;
}

void	*ring_take(t_ring **ring)
{
	void	*content;
	t_ring	*temp_ring;

	temp_ring = (*ring);
	if ((*ring)->next == *ring)
		*ring = NULL;
	else
	{
		*ring = (*ring)->next;
		(*ring)->prev = temp_ring->prev;
		temp_ring->prev->next = *ring;
	}
	temp_ring->next = NULL;
	temp_ring->prev = NULL;
	content = temp_ring->content;
	free(temp_ring);
	temp_ring = NULL;
	return (content);
}