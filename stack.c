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

t_stack	*new_stack()
{
	t_list	*head;
	t_stack	*stack;

	head = malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		free(head);
		return (NULL);
	}
	stack->head = head;
	return (stack);
}

void	push(t_stack *stack, void *content)
{
	if (stack == NULL)
		return ;
	ft_lstadd_front(&stack->head, content);
}

/* If NULL has been inserted then pop returns values that are indistinguishable
 * from invalid behaviour.
 */
void	*pop(t_stack *stack)
{
	void	*content;
	t_list	*temp;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	temp = stack->head;
	stack->head = stack->head->next;
	content = temp->content;
	temp->next = NULL;
	free(temp);
	return (content);
}

// del is not required. If NULL is passed, we assume that the caller knows
// that the stack is empty.
void	del_stack(t_stack **stack, void (*del)(void*))
{
	if (*stack == NULL)
		return ;
	if (del != NULL)
		ft_lstclear(&(*stack)->head, del);
	free((*stack)->head);
	free(*stack);
	*stack = NULL;
}