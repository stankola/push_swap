/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:52:25 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 12:52:27 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "stack.h"
#include "ring.h"

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

void	print_binary(int value, int padding)
{
	char bits[33] = {0};
	int i = 31;
	int mask = 1;
	bits[32] = '\0';
	bits[31] = '0';
	while (mask <= value)
	{
		if (value & mask)
			bits[i--] = '1';
		else 
			bits[i--] = '0';
		mask <<= 1;
		padding--;
	}
	if (value == 0)
	{
		i = 30;
		padding--;
	}
	while (padding-- > 0)
		bits[i--] = ' ';
	ft_printf("%s", &bits[++i]);
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
//			print_binary(*(int*)a_iterator->content, 8);
			a_iterator = a_iterator->prev;
		}
//		else
//			ft_printf("\t");
		if (b_iterator != NULL)
		{
			ft_printf("\t%d", *(int*)b_iterator->content);
//			ft_printf("\t");
//			print_binary(*(int*)b_iterator->content, 8);
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
