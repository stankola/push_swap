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
#ifndef PS_MAX
# define PS_MAX 2147483648
#endif
#ifndef PS_MIN
# define PS_MIN -2147483649
#endif

int	is_duplicates(int iarr[], int size)
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

static int	*get_ptr_to_next_min_value(int iarr[], long int cur_min, int size)
{
	long int	next_min;
	int			i;
	int			*iptr;

	i = 0;
	next_min = (long)PS_MAX;
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
	iptr_arr = malloc(sizeof(int *) * size);
	if (iptr_arr == NULL)
		return ;
	current_min = get_ptr_to_next_min_value(iarr, (long)PS_MIN, size);
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

// Expects NULL terminated array
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
int	is_sorted(t_ring *ring)
{
	int		current_min;
	t_ring	*iterator;

	if (ring == NULL)
		return (1);
	iterator = ring;
	current_min = *(int *)iterator->content;
	iterator = iterator->prev;
	while (iterator != ring)
	{
		if (current_min <= *(int *)iterator->content)
			current_min = *(int *)iterator->content;
		else
			return (0);
		iterator = iterator->prev;
	}
	return (1);
}
