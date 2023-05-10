/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:02:52 by tsankola          #+#    #+#             */
/*   Updated: 2023/03/20 16:02:53 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sorting_algorithms.h"
#include "push_swap_operations.h"
#include "push_swap.h"

// Current max element of sub_stack should remain on top.
static void sorting_step(t_stack *stacks[], t_stack *command_stack, int sub_size)
{
	execute(stacks, command_stack, ps_pa);
	if (*(int*)ft_peek(stacks[a]) < *(int*)ft_peek(stacks[b]))
	{
		execute(stacks, command_stack, ps_pb);
		execute(stacks, command_stack, ps_sa);
	}
	else
		execute(stacks, command_stack, ps_pb);
	if (sub_size > 2)
	{
		execute(stacks, command_stack, ps_rra);
		sorting_step(stacks, command_stack, sub_size - 1);
	}
	execute(stacks, command_stack, ps_ra);
}

t_stack	*insertion_sort(t_stack *stacks[])
{
	t_stack	*command_stack;
	int		sub_size;
	int		size;

	if (stacks == NULL || stacks[a] == NULL || stacks[b] == NULL)
		return (NULL);
	command_stack = ft_new_stack();
	if (command_stack == NULL)
		return (NULL);
	size = get_stack_size(stacks[a]);
	if (size <= 1)
		return command_stack;
	sub_size = 2;
	while (sub_size <= size)
		sorting_step(stacks, command_stack, sub_size++);
	execute(stacks, command_stack, ps_ra);
	return (command_stack);
}