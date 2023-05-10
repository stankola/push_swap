/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:37:27 by tsankola          #+#    #+#             */
/*   Updated: 2023/03/24 13:52:06 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_operations.h"

// Swaps the position of the first two elements of stack
void	ps_swap(t_stack *stack)
{
	void	*temp1;
	void	*temp2;

	if (stack == NULL)
		return ;
	temp1 = ft_pop(stack);
	temp2 = ft_pop(stack);
	ft_push(stack, temp1);
	ft_push(stack, temp2);
}

// Pushes the first element from stack_a to stack_b
void	ps_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (ft_peek(stack_a) != NULL)
		ft_push(stack_b, ft_pop(stack_a));
}

// Rotates the stack so that the first element becomes the last
void	ps_rotate(t_stack *stack)
{
	void	*temp_first;
	t_stack	*temp_stack;

	if (stack == NULL)
		return ;
	temp_first = ft_pop(stack);
	if (temp_first == NULL)
		return ;
	temp_stack = ft_new_stack();
	if (temp_stack == NULL)
		return ;
	stack_to_stack(stack, temp_stack);
	ft_push(stack, temp_first);
	stack_to_stack(temp_stack, stack);
	ft_del_stack(&temp_stack, NULL);
}

// Rotates the stack so that the last element becomes the first
void	ps_reverse_rotate(t_stack *stack)
{
	void	*temp_last;
	t_stack	*temp_stack;

	if (stack == NULL)
		return ;
	temp_stack = ft_new_stack();
	if (temp_stack == NULL)
		return ;
	stack_to_stack(stack, temp_stack);
	temp_last = ft_pop(temp_stack);
	if (temp_last == NULL)
	{
		ft_del_stack(&temp_stack, NULL);
		return ;
	}
	stack_to_stack(temp_stack, stack);
	ft_push(stack, temp_last);
	ft_del_stack(&temp_stack, NULL);
}
