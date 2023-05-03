/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:21:26 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/02 15:21:28 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int		countwords(char *strarr[])
{
	int	i;

	i = 0;
	while (strarr[i] != NULL)
		i++;
	return (i);
}

void	print_stacks(t_stack *const stacks[])
{
	t_stack *temp_stack_a;
	t_stack *temp_stack_b;
	int		*a_iterator;
	int		*b_iterator;

	if (stacks == NULL || stacks[a] == NULL || stacks[b] == NULL)
		return ;
	temp_stack_a = ft_new_stack();
	if (temp_stack_a == NULL)
		return ;
	temp_stack_b = ft_new_stack();
	if (temp_stack_a == NULL)
	{
		free(temp_stack_a);
		return ;
	}
	a_iterator = (int*)ft_pop(stacks[a]);
	b_iterator = (int*)ft_pop(stacks[b]);
	while (a_iterator != NULL || b_iterator != NULL)
	{
		if (a_iterator != NULL)
			ft_printf("%d", *a_iterator);
		if (b_iterator != NULL)
			ft_printf("\t%d", *b_iterator);
		ft_printf("\n");
		ft_push(temp_stack_a, a_iterator);
		ft_push(temp_stack_b, b_iterator);
		a_iterator = (int*)ft_pop(stacks[a]);
		b_iterator = (int*)ft_pop(stacks[b]);
	}
	stack_to_stack(temp_stack_a, stacks[a]);
	stack_to_stack(temp_stack_b, stacks[b]);
	ft_printf("---------\na\tb\n");
}

void	print_rings(t_ring *rings[])
{
	t_ring	*a_iterator;
	t_ring	*b_iterator;

	if (rings == NULL)
		return ;
	a_iterator = rings[a];
	b_iterator = rings[b];
	while (a_iterator != NULL || b_iterator != NULL)
	{
		if (a_iterator != NULL)
		{
			ft_printf("%d", *(int*)a_iterator->content);
			a_iterator = a_iterator->prev;
		}
		if (b_iterator != NULL)
		{
			ft_printf("\t%d", *(int*)b_iterator->content);
			b_iterator = b_iterator->prev;
		}
		ft_printf("\n");
		if (a_iterator == rings[a])
			a_iterator = NULL;
		if (b_iterator == rings[b])
			b_iterator = NULL;
	}
	ft_printf("---------\na\tb\n");
}

/* Checks to see if stack is in order using integer comparison.
 * Const keyword might be misleading since the stack itself is modified during 
 * execution. However, it should be returned to its original order.
 * TODO: Test. Probably works, not 100% sure. Might not be needed.
 */
int		is_sorted(t_stack *stack)
{
	t_stack	*temp_stack;

	if (stack == NULL)
		return -1;
	temp_stack = ft_new_stack();
	if (temp_stack == NULL)
		return (-1);
	while (ft_peek(stack) != NULL)
	{
		if ((ft_peek(temp_stack) == NULL) ||
			(*(int*)ft_peek(stack) >= *(int*)ft_peek(temp_stack)))
			ft_push(temp_stack, ft_pop(stack));
		else
		{
			stack_to_stack(temp_stack, stack);
			ft_del_stack(&temp_stack, NULL);
			return (0);
		}
	}
	stack_to_stack(temp_stack, stack);
	ft_del_stack(&temp_stack, NULL);
	return (1);
}
