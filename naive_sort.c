/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:38:46 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/06 17:38:47 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_min_value(const t_list *stack)
{
	int	min;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	min = *(int*)stack->content;
	while (stack != NULL)
	{
		if (min > *(int*)stack->content)
			min = *(int*)stack->content;
		stack = stack->next;
	}
	return (min);
}

void naive_sort(t_list *stacks[])
{
	int	min;

	if (stacks == NULL)
		return ;
	while (stacks[a] != NULL)
	{
		min = get_min_value(stacks[a]);
		while (*(int*)stacks[a]->content != min)
			rotate(&stacks[a]);
		push(&stacks[a], &stacks[b]);
	}
	while (stacks[b] != NULL)
		push(&stacks[b], &stacks[a]);
}