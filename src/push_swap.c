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
#include "libft.h"
#ifndef INT_MAX
# define INT_MAX 2147483647
#endif
#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

int	check_duplicates(int iarr[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (++j < size)
		{
			if (iarr[i] == iarr[j])
				return (1);
		}
		i++;
	}
	return (0);
}

static int	*get_ptr_to_next_min_value(int iarr[], int cur_min, int size)
{
	int	next_min;
	int	i;
	int	*iptr;

	i = 0;
	next_min = INT_MAX;
	while (i < size)
	{
		if (iarr[i] < next_min && iarr[i] > cur_min)
		{
			next_min = iarr[i];
			iptr = &(iarr[i]);
		}
		i++;
	}
	return (iptr);
}

void	normalize_array(int iarr[], int size)
{
	int	**iptr_arr;
	int	i;
	int	*current_min;

	if (size <= 0)
		return ;
	iptr_arr = malloc(sizeof(int*) * size);
	if (iptr_arr == NULL)
		return ;
	current_min = get_ptr_to_next_min_value(iarr, INT_MIN, size);
	iptr_arr[0] = current_min;
	i = 1;
	while (i < size)
	{
		current_min = get_ptr_to_next_min_value(iarr, *current_min, size);
		iptr_arr[i++] = current_min;
	}
	while (--i >= 0)
	{
		*(iptr_arr[i]) = i;
	}
	free(iptr_arr);
}

int	countwords(char *strarr[])
{
	int	i;

	i = 0;
	while (strarr[i] != NULL)
		i++;
	return (i);
}

/* Checks to see if stack is in order using integer comparison.
 * Const keyword might be misleading since the stack itself is modified during 
 * execution. However, it should be returned to its original order.
 */
int	is_sorted(t_stack *stack) // TODO: Test. Probably works, not 100% sure. Might not be needed.
{
	t_stack	*temp_stack;

	if (stack == NULL)
		return (-1);
	temp_stack = ft_new_stack();
	if (temp_stack == NULL)
		return (-1);
	while (ft_peek(stack) != NULL)
	{
		if ((ft_peek(temp_stack) == NULL)
			|| (*(int*)ft_peek(stack) >= *(int*)ft_peek(temp_stack)))
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
