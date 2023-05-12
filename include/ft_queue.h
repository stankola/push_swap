/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:15:46 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 12:15:46 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_QUEUE_H
# define FT_QUEUE_H
# include "libft.h"

typedef struct s_queue
{
	t_list		*head;
	t_list		*tail;
}				t_queue;

void	ft_enqueue(t_queue **queue, void *content);

void	*ft_dequeue(t_queue **queue);

int		ft_queueisempty(t_queue *q);

void	ft_queueclear(t_queue **queue, void (*del)(void*));

void	*ft_queuepeek(t_queue *queue);

#endif
