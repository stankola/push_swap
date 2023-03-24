/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:40:32 by tsankola          #+#    #+#             */
/*   Updated: 2023/03/20 18:40:32 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

t_stack	*ft_new_stack()
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	return (stack);
}

/* NULL value for content is not supported because they would break the logic
 * If ft_lstnew fails, nothing will be added and it may not be detected. This
 * could be fixed if the function returned a "boolean" value, for instance.
 */
void	ft_push(t_stack *stack, void *content)
{
	t_list	*node;

	if (stack == NULL || content == NULL)
		return ;
	node = ft_lstnew(content);
	if (node == NULL)
		return ;
	ft_lstadd_front(&stack->head, node);
}

void	*ft_pop(t_stack *stack)
{
	void	*content;
	t_list	*node;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	node = stack->head;
	stack->head = stack->head->next;
	content = node->content;
	node->next = NULL;
	free(node);
	return (content);
}

/* del is not required. If NULL is passed, assume that the stack is empty.
 */
void	ft_del_stack(t_stack **stack, void (*del)(void*))
{
	if (*stack == NULL)
		return ;
	if (del != NULL)
		ft_lstclear(&(*stack)->head, del);
	free((*stack)->head);
	free(*stack);
	*stack = NULL;
}

/* Returns pointer to first element.
 */
void	*ft_peek(t_stack *stack)
{
	void	*ptr;

	ptr = ft_pop(stack);
	ft_push(stack, ptr);
	return (ptr);
}
