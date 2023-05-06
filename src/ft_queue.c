/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:21:40 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/03 19:21:41 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_queue.h"
#include <stdio.h>	// testing

// Standard FIFO queue
t_queue	*ft_queuenew(void)
{
	t_queue	*queue;
	queue = malloc(sizeof(t_queue));
	if (queue == NULL)
		return (NULL);
	queue->head = NULL;
	queue->tail = NULL;
	return (queue);
}

/* 
 * "Smart" enqueue and dequeue that creates or frees itself if NULL or empty.
 * Not sure if good idea in practice.
 * Dequeue could perhaps free itself only if called when queue is empty.
 * 
 * 6.5.2023: I think it's a good idea
 */
void	ft_enqueue(t_queue **queue, void *content)
{
	t_list	*node;

	if (queue == NULL)
		exit(EXIT_FAILURE);
	node = ft_lstnew(content);
	if (node == NULL)
		exit(EXIT_FAILURE);
	if (*queue == NULL)
		*queue = ft_queuenew();
	if (*queue == NULL)
		exit(EXIT_FAILURE);
	ft_lstadd_back(&(*queue)->tail, node);
	(*queue)->tail = node;
	if ((*queue)->head == NULL)
		(*queue)->head = (*queue)->tail;
}

void	*ft_dequeue(t_queue **queue)
{
	void	*content;
	t_list	*node;

	if (queue == NULL)
		exit(EXIT_FAILURE);
	if (*queue == NULL || (*queue)->head == NULL)	// Latter clause probably redundant
		return (NULL);
	content = (*queue)->head->content;
	node = (*queue)->head;
	(*queue)->head = node->next;
	if (node == (*queue)->tail)
		(*queue)->tail = NULL;
	free(node);
	if ((*queue)->head == NULL && (*queue)->tail == NULL)
	{
		free(*queue);
		(*queue)->tail = NULL;
		(*queue)->head = NULL;
		*queue = NULL;
	}
	return (content);
}

int		ft_queueisempty(t_queue *q)
{
	if (q->tail == NULL && q->head == NULL)
		return (1);
	else
		return (0);
}

void	ft_queueclear(t_queue **queue, void (*del)(void*))
{
	if (queue == NULL || del == NULL)
		return ;
	ft_lstclear(&(*queue)->head, del);
	(*queue)->tail = NULL;
	(*queue)->head = NULL;
	free(*queue);
	*queue = NULL;
}

void	*ft_queuepeek(t_queue *queue)
{
	return (queue->head->content);
}

// TESTING Below
/*
void	deli(int *i)
{
	return ;
}

int		main(void)
{
	int	values[] = {1,2,3,4,5,6};
	t_queue	*q;

	q = ft_queuenew();
	printf("Queue created\n");
	ft_enqueue(&q, &values[1]);
	ft_enqueue(&q, &values[3]);
	ft_dequeue(&q);
	ft_enqueue(&q, &values[4]);
	ft_enqueue(&q, &values[5]);
	printf("Enqueues ok\n");
	
	int *itr;
	itr = (int*)ft_dequeue(&q);
	while (itr != NULL)
	{
		printf("%d\n", *itr);
		itr = (int*)ft_dequeue(&q);
	}
	ft_enqueue(&q, &values[2]);
	ft_enqueue(&q, &values[0]);
	itr = (int*)ft_dequeue(&q);
	while (itr != NULL)
	{
		printf("%d\n", *itr);
		itr = (int*)ft_dequeue(&q);
	}
	ft_enqueue(&q, &values[1]);
	ft_enqueue(&q, &values[3]);
	ft_queueclear(&q, (void (*)(void*))deli);
	printf("%p\n", q);

	system("Leaks qu");
	return (1);
}*/