// TODO header
#ifndef FT_QUEUE_H
# define FT_QUEUE_H
# include "libft.h"


typedef struct	s_queue
{
	t_list		*head;
	t_list		*tail;
}				t_queue;

t_queue	*ft_queuenew(void);

void	ft_enqueue(t_queue **queue, void *content);

void	*ft_dequeue(t_queue **queue);

int		ft_queueisempty(t_queue *q);

void	ft_queueclear(t_queue **queue, void (*del)(void*));

void	*ft_queuepeek(t_queue *queue);

#endif