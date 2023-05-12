/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <tsankola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:38:05 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 14:41:13 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stack.h"

// Pops the stack completely over to the other stack, reversing the order
void	stack_to_stack(t_stack *stack_a, t_stack *stack_b)
{
	void	*temp_content;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	temp_content = ft_pop(stack_a);
	while (temp_content != NULL)
	{
		ft_push(stack_b, temp_content);
		temp_content = ft_pop(stack_a);
	}
}

int	get_stack_size(t_stack *stack)
{
	t_stack	*temp_stack;
	int		i;

	if (stack == NULL)
		return (-1);
	if (ft_peek(stack) == NULL)
		return (0);
	temp_stack = ft_new_stack();
	if (temp_stack == NULL)
		return (-1);
	i = 0;
	while (ft_peek(stack) != NULL)
	{
		i++;
		ft_push(temp_stack, ft_pop(stack));
	}
	stack_to_stack(temp_stack, stack);
	ft_del_stack(&temp_stack, NULL);
	return (i);
}
