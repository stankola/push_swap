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

// Might overflow. TODO: Consider this
static int	power(int x, int y)
{
	int	result;

	result = 1;
	if (y == 0)
		return (result);
	while (y > 0)
	{
		result *= x;
		y--;
	}
	while (y < 0)
	{
		result *= 1 / x;
		y++;
	}
	return (result);
}

// TODO: Consider size < 2
// TODO: Consider offset values when size is not a power of 2
static void	divide_step(t_stack *stacks[], t_stack *command_stack, int size)
{
	int	i;
	int	x;

	i = 0;
	ft_printf("size: %d\n", size);	// TEST
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
		i++;
	}
	if (size % 2 != 0)
	{
//		if (size % 4 == 3)
//		{
			execute(stacks, command_stack, ps_pa);
			execute(stacks, command_stack, ps_rb);
//		}
//		if (size % 4 == 1)
//			execute(stacks, command_stack, ps_ra);
	}
}

static void merge_left(t_stack *stacks[], t_stack *command_stack, int a_height, int b_height)
{
	ft_printf("left%d %d\n", a_height, b_height);	// TEST
	while (a_height > 0 || b_height > 0)
	{
		if (((a_height != 0 && b_height != 0)
			&& (*(int*)ft_peek(stacks[a]) > *(int*)ft_peek(stacks[b])))
			|| (a_height == 0))
		{
			b_height--;
			execute(stacks, command_stack, ps_pb);
		}
		else 
			a_height--;
		execute(stacks, command_stack, ps_ra);
	}
}

static void merge_right(t_stack *stacks[], t_stack *command_stack, int a_height, int b_height)
{
	ft_printf("right %d %d\n", a_height, b_height);
	while (a_height > 0 || b_height > 0)
	{
		if (((a_height != 0 && b_height != 0)
			&& (*(int*)ft_peek(stacks[a]) < *(int*)ft_peek(stacks[b])))
			|| (b_height == 0))
			{
				a_height--;
				execute(stacks, command_stack, ps_pa);
			}
			else 
				b_height--;
		execute(stacks, command_stack, ps_rb);
	}
}

static void	sorting_step(t_stack *stacks[], t_stack *command_stack, int step, int size)
{
	int	i;
	int	leftovers;

	i = 0;
	ft_printf("step %d\n", step);
	while (i < size / power(2, step + 1))	// Perhaps <= to account for leftover values? Or another loop for them
	{
		if (i % 2 == 0)
		{
			merge_left(stacks, command_stack, power(2, step), power(2, step));
			print_stacks(stacks);
		}
		else
		{
			merge_right(stacks, command_stack, power(2, step), power(2, step));
			print_stacks(stacks);
		}
		i++;
	}
	leftovers = size % power(2, step + 1);
	ft_printf("%d values unhandled\n", leftovers);
//	int	right_leftovers;
//	int	left_leftovers;
	if (leftovers > 0)
	{
		if (step % 2 == 0)
			merge_right(stacks, command_stack, leftovers - (leftovers / power(2, step)), 0);
		else
			merge_left(stacks, command_stack, (leftovers / power(2, step)) * power(2, step), leftovers % power(2, step));
	}
}

t_stack	*merge_sort(t_stack *stacks[])
{
	t_stack	*command_stack;
	int		size;
	int		step;

	if (stacks == NULL || stacks[a] == NULL || stacks[b] == NULL)
		return (NULL);
	command_stack = ft_new_stack();
	if (command_stack == NULL)
		return (NULL);
	size = get_stack_size(stacks[a]);
	// divide stack
	print_stacks(stacks);		// TEST
	ft_printf("Dividing\n");	// TEST
	divide_step(stacks, command_stack, size);
	print_stacks(stacks);		// TEST
	// while unsorted sort from 2^n to size, where n = 0, 1, 2, 3...
	ft_printf("Sorting ");		// TEST
	step = 1;
	while (size / power(2, step + 1) > 0)
	{
		sorting_step(stacks, command_stack, step++, size);
		ft_printf("After Sorting\n");		// TEST
		print_stacks(stacks);
	}
	return (command_stack);
}