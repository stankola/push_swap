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

/* Standard FIFO queue
 * "Smart" enqueue and dequeue that creates or frees itself if NULL or empty.
 * Not sure if it's good practice.
 * Dequeue could perhaps free itself only if called when queue is empty.
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
	{
		*queue = malloc(sizeof(t_queue));
		if (*queue == NULL)
			exit(EXIT_FAILURE);
		(*queue)->head = NULL;
		(*queue)->tail = NULL;
	}
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
	if (*queue == NULL)
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

int	ft_queueisempty(t_queue *q)
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
