/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:35:35 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/06 19:35:36 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "sorting_algorithms.h"
#include "ft_printf.h" // TESTING

// Might overflow. TODO: Consider this
static int	power(int x, int y)
{
	int	result;

	result = 1;
	if (y = 0)
		return (result);
	while (y-- > 0)
		result *= x;
	while (y++ < 0)
		result *= 1 / x;
	return (result);
}

// TODO: Consider size < 2
// TODO: Consider offset values when size is not a power of 2
static void	divide_step(t_stack *stacks[], t_stack *command_stack, int size)
{
	int	i;
	int	x;

	i = 0;
	while (i < size / 2)
	{
		x = *(int*)ft_peek(stacks[a]);
		execute(stacks, command_stack, ps_sa);
		if (i % 2 == 0)
		{
			if (x < *(int*)ft_peek(stacks[a]))
				execute(stacks, command_stack, ps_sa);
			execute(stacks, command_stack, ps_ra);
			execute(stacks, command_stack, ps_ra);
		}
		else
		{
			if (x > *(int*)ft_peek(stacks[a]))
				execute(stacks, command_stack, ps_sa);
			execute(stacks, command_stack, ps_pa);
			execute(stacks, command_stack, ps_pa);
		}
	}
}

static void sorting_step(t_stack *stacks[], t_stack *command_stack, int step, int size)
{
	int	*iptr;
	int	i;
	int	j;

	i = 0;
	while (i < size)	// Check upper limit
	{
		j = 0;
		if (i % 2 == 0)
		{
			while (j < power(step, 2))
			{
				if (*(int*)ft_peek(stacks[a]) > *(int*)ft_peek(stacks[b]))
					execute(stacks, command_stack, ps_pb);
				execute(stacks, command_stack, ps_ra);
				// TODO: How to keep track of how many values have been sorted
				// from each side? Maybe left and right side counter?
			}
		}
		else
		{

		}
		i++;
	}
}

t_stack	*merge_sort(t_stack *stacks[])
{
	t_stack	*command_stack;
	int		size;
	int		i;

	if (stacks == NULL || stacks[a] == NULL || stacks[b] == NULL)
		return (NULL);
	command_stack = ft_new_stack();
	if (command_stack == NULL)
		return (NULL);
	size = get_stack_size(stacks[a])
	// divide stack
	ft_printf("Dividing\n");	// TEST
	divide_step(stacks, command_stack, size);
	print_stacks(stacks);		// TEST
	// while unsorted sort from n² to size, where n = 0, 1, 2, 3...
	ft_printf("Sorting\n");		// TEST
	sorting_step(stacks, command_stack, size);
}