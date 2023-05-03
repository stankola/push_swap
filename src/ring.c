#include "ring.h"
#include <stdlib.h>
#include <stdio.h> //TEST

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
	temp_ring = NULL;
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
/*
int main(void)	//TEST
{
	t_ring *ringu;

	int taulu[] = {1,2,3,4,5};
//	ringu = ring_new(&taulu[0]);
//	printf("%d\n", *(int*)ring_take(&ringu));
//	ring_add(&ringu, &taulu[1]);
//	printf("%d\n", *(int*)ring_take(&ringu));

//	ring_add(&ringu, &taulu[1]);
//	ring_add(&ringu, &taulu[2]);
//	ring_add(&ringu, &taulu[2]);
//	ring_add(&ringu, &taulu[4]);
//	ring_add(&ringu, &taulu[3]);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", *(int*)ringu->content);
//		ringu = ringu->prev;
//	}
//	printf("%p\n", ringu);
	
	ringu = NULL;
	ring_add(&ringu, &taulu[1]);	//2
	printf("cur %d next %d prev %d\n", *(int*)ringu->content, *(int*)ringu->next->content, *(int*)ringu->prev->content);
	ring_add(&ringu, &taulu[3]);	//4
	printf("cur %d next %d prev %d\n", *(int*)ringu->content, *(int*)ringu->next->content, *(int*)ringu->prev->content);
	ring_add(&ringu, &taulu[0]);	//1
	printf("cur %d next %d prev %d\n", *(int*)ringu->content, *(int*)ringu->next->content, *(int*)ringu->prev->content);
	ring_rotate(&ringu);
	printf("took %d\n", *(int*)ring_take(&ringu));
	printf("cur %d next %d prev %d\n", *(int*)ringu->content, *(int*)ringu->next->content, *(int*)ringu->prev->content);
	printf("took %d\n", *(int*)ring_take(&ringu));
	printf("cur %d next %d prev %d\n", *(int*)ringu->content, *(int*)ringu->next->content, *(int*)ringu->prev->content);
	printf("took %d\n", *(int*)ring_take(&ringu));
	printf("cur %d next %d prev %d\n", *(int*)ringu->content, *(int*)ringu->next->content, *(int*)ringu->prev->content);
}*/