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

/* Works by finding the minimum value from stack a and pushes it to stack b for
 * as long as there are values in stack a.
 */
static int	get_min_value(const t_stack *stack)
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

t_stack *naive_sort(t_stack *stacks[])
{
	t_stack	*command_stack;
	int		min;

	if (stacks == NULL || stacks[a] == NULL || stacks[b] == NULL)
		return (NULL);
	command_stack = ft_new_stack();
	if (command_stack == NULL)
		return (NULL);
	while (stacks[a] != NULL)
	{
		min = get_min_value(stacks[a]);
		while (*(int*)stacks[a]->content != min)
			ps_rotate(&stacks[a]);
		ps_push(&stacks[a], &stacks[b]);
	}
	while (stacks[b] != NULL)
		ps_push(&stacks[b], &stacks[a]);
}