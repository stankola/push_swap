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
static void sorting_step(t_list *stacks[], int sub_size)
{
	// First compare first elements and swap if necessary
	push(&stacks[a], &stacks[b]);
	if (*(int*)stacks[a]->content < *(int*)stacks[b]->content)
	{
		push(&stacks[b], &stacks[a]);
		swap(&stacks[a]);
	}
	else
		push(&stacks[b], &stacks[a]);
	ft_printf("Comparison(+swap) done\n");
	print_stacks(stacks);
	// Then move upwards in substack
	if (sub_size > 2)
	{
		reverse_rotate(&stacks[a]);	// Last element becomes the first
		sorting_step(stacks, sub_size - 1);	// iterate through substack recursively
	}
	rotate(&stacks[a]);
}

void	insertion_sort(t_list *stacks[])
{
	int	sub_size;	// sorted subarray
	int	size;

	if (is_sorted(stacks))	// WHAT IF: stacks == NULL
	{
		ft_printf("Sorted!\n");
		return ;
	}
	size = ft_lstsize(stacks[a]);
	if (size <= 1)
	{
		ft_printf("Aborting sort, size = %d\n", size);
		return ;
	}
	sub_size = 2;
	while (sub_size <= size)
	{
		ft_printf("calling sorting step, sub_size: %d\n", sub_size);
		print_stacks(stacks);
		sorting_step(stacks, sub_size++);
	}
	rotate(&stacks[a]);
	ft_printf("Finished\n");
	print_stacks(stacks);
}

/*
 * 1. push(a,b);
	if first(a) < first(b)
		push(b,a);
		swap(a);
	else
		push(b,a);


*/