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
#include "push_swap.h"
#include "ft_printf.h"	//TESTING

// Current max element of sub_stack should remain on top.
static void sorting_step(t_stack *stacks[], t_stack *command_stack, int sub_size)
{
	// First compare first elements and swap if necessary
	execute(stacks, command_stack, ps_pa);	//ps_push(stacks[a], stacks[b]);
	if (*(int*)peek(stacks[a]) < *(int*)peek(stacks[b]))
	{
		execute(stacks, command_stack, ps_pb);	//ps_push(stacks[b], stacks[a]);
		execute(stacks, command_stack, ps_sa);	//ps_swap(stacks[a]);
	}
	else
		execute(stacks, command_stack, ps_pb);	//ps_push(stacks[b], stacks[a]);
//	ft_printf("Comparison(+swap) done\n");
//	print_stacks(stacks);
	// Then move upwards in substack
	if (sub_size > 2)
	{
		execute(stacks, command_stack, ps_rra);	//ps_reverse_rotate(stacks[a]);	// Last element becomes the first
		sorting_step(stacks, command_stack, sub_size - 1);	// iterate through substack recursively
	}
	execute(stacks, command_stack, ps_ra);	//ps_rotate(stacks[a]);
}

t_stack	*insertion_sort(t_stack *stacks[])
{
	t_stack	*command_stack;
	int		sub_size;	// sorted subarray
	int		size;

	command_stack = new_stack();
	if (command_stack == NULL)
		return (NULL);
	size = get_stack_size(stacks[a]);
	if (size <= 1)
		return command_stack;
	sub_size = 2;
	while (sub_size <= size)
	{
//		ft_printf("calling sorting step, sub_size: %d\n", sub_size);
//		print_stacks(stacks);
		sorting_step(stacks, command_stack, sub_size++);
	}
	execute(stacks, command_stack, ps_ra);	//ps_rotate(stacks[a]);
//	ft_printf("Finished\n");
	print_stacks(stacks);
	return (command_stack);
}