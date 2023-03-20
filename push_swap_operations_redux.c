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
#include "stack.h"
#include <stdio.h>		// TESTING

// Swaps the position of the first two elements of stack
void	swap(t_stack *stack)
{
	void	*temp1;
	void	*temp2;

	if (stack == NULL || stack->head == NULL)
		return ;
	temp1 = pop(stack);
	temp2 = pop(stack);
	if (temp2 == NULL)
	push(stack, temp1);
	if (temp2 != NULL)
		push(stack, temp2);
}

// Pushes the first element from stack_a to stack_b
void	push(t_stack *stack_a, t_stack *stack_b)
{
	void	*temp;

	if (stack_a == NULL || stack_b == NULL
		|| stack_a->head == NULL || stack_b->head == NULL)
		return ;
	temp = pop(stack_a);
	if (temp != NULL)
		push(stack_b, pop(stack_a));
}

// Rotates the stack so that the last element becomes the first
void	reverse_rotate(t_stack *stack)
{
	void	*temp_last;
	t_stack	*temp_stack;
	void	*temp_content;

	if (stack == NULL || stack->head == NULL)
		return ;
	temp_stack = new_stack();
	temp_content = pop(stack);
	if (temp_content == NULL)
		return ;
	while (temp_content != NULL)
	{
		push(temp_stack, temp_content);
		temp_content = pop(stack);
	}
	temp_content = pop(temp_stack);
	temp_last = temp_content;
	while (temp_content != NULL)
	{
		push(stack, temp_content);
		temp_content = pop(temp_stack);
	}
	push(stack, temp_last);
	del_stack(&temp_stack, NULL);
}

// Rotates the stack so that the first element becomes the last
void	rotate(t_stack *stack)
{
	void	*temp_first;
	t_stack	*temp_stack;
	void	*temp_content;

	if (stack == NULL || stack->head == NULL)
		return ;
	temp_stack = new_stack();
	temp_content = pop(stack);
	if (temp_content == NULL)
		return ;
	temp_first = temp_content;
	temp_content = pop(stack);
	while (temp_content != NULL)
	{
		push(temp_stack, temp_content);
		temp_content = pop(stack);
	}
	push(stack, temp_first);
	temp_content = pop(temp_stack);
	while (temp_content != NULL)
	{
		push(stack, temp_content);
		temp_content = pop(temp_stack);
	}
	del_stack(&temp_stack, NULL);
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