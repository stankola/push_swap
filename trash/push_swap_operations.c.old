/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:37:27 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/02 15:37:28 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>		// TESTING

// Swaps the position of the first two elements of stack
void	swap(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

// Pushes the first element from stack_a to stack_b
void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	ft_lstadd_front(stack_b, temp);
}

// Rotates the stack so that the last element becomes the first
void	reverse_rotate(t_list **stack)
{
	t_list	*next_to_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	next_to_last = *stack;
	while (next_to_last->next->next != NULL)
		next_to_last = next_to_last->next;
	next_to_last->next->next = *stack;
	*stack = next_to_last->next;
	next_to_last->next = NULL;
}

// Rotates the stack so that the first element becomes the last
void	rotate(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = NULL;
	ft_lstlast(temp)->next = *stack;
	*stack = temp;
}

// TRASH
/*
t_list	*swa(t_list *stack)
{
	t_list	*temp;
	t_list	*swapped;

	if (stack == NULL)
		return (NULL);
	swapped = ft_lstmap(stack, (void*(*)(void*))copy_int_ptr, (void (*)(void*))del_int_ptr);
	temp = swapped->next;
	swapped->next = temp->next;
	temp->next = swapped;
	swapped = temp;
	return (swapped);
}

t_list	**pus(t_list *stack_a, t_list *stack_b)
{
	t_list *temp;
	t_list	*pushed_a;
	t_list	*pushed_b;
	t_list	**pusheds;

	if (stack_a == NULL)
		return (NULL);
	pushed_a = ft_lstmap(stack_a, (void*(*)(void*))copy_int_ptr, (void (*)(void*))del_int_ptr);
	pushed_b = ft_lstmap(stack_b, (void*(*)(void*))copy_int_ptr, (void (*)(void*))del_int_ptr);
	temp = pushed_a;
	pushed_a = temp->next;
	ft_lstadd_front(&pushed_b, temp);
	pusheds = malloc(sizeof(t_list*) * 2);
	pusheds[a] = pushed_a;
	pusheds[b] = pushed_a;
	return (pusheds);
}

t_list	*rotat(t_list *stack)
{
	t_list	*next_to_last;
	t_list	*rotated;

	if (stack == NULL || stack->next == NULL)
		return (NULL);
	rotated = ft_lstmap(stack, (void*(*)(void*))copy_int_ptr, (void (*)(void*))del_int_ptr);
	next_to_last = rotated;
	while (next_to_last->next->next != NULL)
		next_to_last = next_to_last->next;
	next_to_last->next->next = rotated;
	rotated = next_to_last->next;
	next_to_last->next = NULL;	
	return (rotated);
}

t_list	*reverse_rotat(t_list *stack)
{
	t_list *temp;
	t_list *rotated;

	if (stack == NULL || stack->next == NULL)
		return (NULL);
	rotated = ft_lstmap(stack, (void*(*)(void*))copy_int_ptr, (void (*)(void*))del_int_ptr);
	temp = rotated->next;
	rotated->next = NULL;
	ft_lstlast(temp)->next = rotated;
	rotated = temp;
	return (rotated);
}
*/