// TODO header

#include "queue.h"
#include "libft.h"

int	queue_contains(t_queue *q, void *state, int (*f)(void*, void*))
{
	t_list	*iterator;

	if (q == NULL)
		return (0);
	iterator = q->head;
	while (iterator != NULL)
	{
		if (f(iterator->content, state))
			return (1);
		iterator = iterator->next;
	}	
	return (0);
}