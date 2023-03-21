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
void	ps_swap(t_stack *stack)
{
	void	*temp1;
	void	*temp2;

	if (stack == NULL)
		return ;
	temp1 = pop(stack);
	temp2 = pop(stack);
	push(stack, temp1);
	push(stack, temp2);
}

// Pushes the first element from stack_a to stack_b
void	ps_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (peek(stack_a) != NULL)
		push(stack_b, pop(stack_a));
}

// Rotates the stack so that the first element becomes the last
void	ps_rotate(t_stack *stack)
{
	void	*temp_first;
	t_stack	*temp_stack;

	if (stack == NULL)
		return ;
	temp_first = pop(stack);
	if (temp_first == NULL)
		return ;
	temp_stack = new_stack();
	if (temp_stack == NULL)
		return ;
	stack_to_stack(stack, temp_stack);
	push(stack, temp_first);
	stack_to_stack(temp_stack, stack);
	del_stack(&temp_stack, NULL);
}

// Rotates the stack so that the last element becomes the first
void	ps_reverse_rotate(t_stack *stack)
{
	void	*temp_last;
	t_stack	*temp_stack;

	if (stack == NULL)
		return ;
	temp_stack = new_stack();
	if (temp_stack == NULL)
		return ;
	stack_to_stack(stack, temp_stack);
	temp_last = pop(temp_stack);
	if (temp_last == NULL)
	{
		del_stack(&temp_stack, NULL);
		return ;
	}
	stack_to_stack(temp_stack, stack);
	push(stack, temp_last);
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