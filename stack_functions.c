/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:38:05 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/06 18:38:06 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf.h"
#include <stdio.h>	// testing

void	del_int_ptr(int *iptr)
{
	if (iptr != NULL)
		free(iptr);
}

int		compare_iptr(int* a, int *b)
{
	if (a == NULL || b == NULL)
		return (a == b);
	return (*a == *b);
}

/* TODO: Convert to stacks. Is this needed?
int		compare_stacks(t_list *stacks_1[], t_list *stacks_2[])
{
	return (ft_lsteq(stacks_1[a], stacks_2[a], (int(*)(void*, void*))compare_iptr)
		&& ft_lsteq(stacks_1[b], stacks_2[b], (int(*)(void*, void*))compare_iptr));
}*/

int		*copy_int_ptr(int *iptr)
{
	int	*ret;

	if (iptr == NULL)
		return (NULL);
	ret = malloc(sizeof(int));
	if (ret != NULL)
		*ret = *iptr;
	return (ret);
}

/* TODO: Convert to stacks. Is this needed?
t_list	*clone_stack(t_list const *stack)
{
	t_list	*clone;

	clone = ft_lstmap((t_list*)stack, (void*(*)(void*))copy_int_ptr, (void (*)(void*))del_int_ptr); // TODO: fix typecast
	return (clone);
}
*/

/* TODO: Convert to stacks. Is this needed?
t_list	**clone_stacks(t_list const *stacks[])
{
	t_list	**clone;

	clone = malloc((b + 1) * sizeof(t_list*));
	if (clone == NULL)
		return (NULL);
	clone[a] = ft_lstmap((t_list*)stacks[a], (void*(*)(void*))copy_int_ptr, (void (*)(void*))del_int_ptr); // TODO: fix typecast
	clone[b] = ft_lstmap((t_list*)stacks[b], (void*(*)(void*))copy_int_ptr, (void (*)(void*))del_int_ptr); // TODO: fix typecast
	return (clone);
}
*/

/* TODO: Convert to stacks. Is this needed?
int	count_inversions(t_list const *stack)
{
	t_list	const *i;
	t_list	const *i2;
	t_list	const *start;
	int		count;

	start = stack;
	count = 0;
	i = stack;
	while (i != NULL)
	{
		i2 = i->next;
		while (i2 != NULL)
		{
			if (*(int*)i2->content < *(int*)i->content)
				count++;
			i2 = i2->next;
		}
		i = i->next;
	}
	return (count);
}
*/

/* TODO: Convert to stacks. Is this needed?
int	count_reverse_inversions(t_list const *stack) // reversions?
{
	t_list	const *i;
	t_list	const *i2;
	t_list	const *start;
	int		count;

	start = stack;
	count = 0;
	i = stack;
	while (i != NULL)
	{
		i2 = i->next;
		while (i2 != NULL)
		{
			if (*(int*)i2->content > *(int*)i->content)
				count++;
			i2 = i2->next;
		}
		i = i->next;
	}
	return (count);
}
*/

/* TODO: Convert to stacks. Is this needed?
int		measure_disorder(t_list const *stack)
{
	t_list	*clone;
	int		disorder;
	int		temp_disorder;
	int		size;
	int		i;

	clone = clone_stack(stack);
	disorder = count_inversions(clone);
	size = ft_lstsize(clone);
	rotate(&clone);
	i = 0;
	while (++i <= size)
	{
		temp_disorder = count_inversions(clone) + i;
		if (i > size / 2)
			temp_disorder += size - 2 * i;
		disorder = ft_min(disorder, temp_disorder);
		rotate(&clone);
	}
	ft_lstclear(&clone, (void (*)(void*))del_int_ptr);
	return (disorder);
}
*/

/* TODO: Convert to stacks. Is this needed?
// Out of date, missing rotation calculations
int		inverted_measure_disorder(t_list const *stack)
{
	t_list	*clone;
	int		disorder;
	int		temp_disorder;
	int		size;
	int		i;

	clone = clone_stack(stack);
	disorder = count_reverse_inversions(clone);
	size = ft_lstsize(clone);
	disorder += size;
	rotate(&clone);
	i = 0;
	while (++i <= size)
	{
		temp_disorder = count_reverse_inversions(clone) + i + size;
		if (i > size / 2)
			temp_disorder += size - 2 * i;
		disorder = ft_min(disorder, temp_disorder);
		rotate(&clone);
	}
	ft_lstclear(&clone, (void (*)(void*))del_int_ptr);
	return (disorder);
}
*/

/* Checks to see if stack is in order using integer comparison.
 * Const keyword might be misleading since the stack is modified.
 */
int		is_sorted(t_stack *const stack)
{
	t_stack	*temp_stack;
	int i;

	if (stack == NULL)
		return -1;
	temp_stack = new_stack();
	if (temp_stack == NULL)
		return (-1);
	ft_printf("checking sorting\n");
	i = 0;
	while (peek(stack) != NULL)
	{
		ft_printf("%i\n", i);
		if ((peek(temp_stack) == NULL) ||
			(*(int*)peek(stack) >= *(int*)peek(temp_stack)))
			push(temp_stack, pop(stack));
		else
		{
			stack_to_stack(temp_stack, stack);
			del_stack(&temp_stack, NULL);
			return (0);
		}
	}
	stack_to_stack(temp_stack, stack);
	del_stack(&temp_stack, NULL);
	return (1);
}

void	print_stacks(t_stack *const stacks[])
{
	t_stack *temp_stack_a;
	t_stack *temp_stack_b;
	int		*a_iterator;
	int		*b_iterator;

	if (stacks == NULL || stacks[a] == NULL || stacks[b] == NULL)
		return ;
	temp_stack_a = new_stack();
	if (temp_stack_a == NULL)
		return ;
	temp_stack_b = new_stack();
	if (temp_stack_a == NULL)
	{
		free(temp_stack_a);
		return ;
	}
	a_iterator = (int*)pop(stacks[a]);
	b_iterator = (int*)pop(stacks[b]);
	while (a_iterator != NULL || b_iterator != NULL)
	{
		if (a_iterator != NULL)
			ft_printf("%d", *a_iterator);
		if (b_iterator != NULL)
			ft_printf("\t%d", *b_iterator);
		ft_printf("\n");
		push(temp_stack_a, a_iterator);
		push(temp_stack_b, b_iterator);
		a_iterator = (int*)pop(stacks[a]);
		b_iterator = (int*)pop(stacks[b]);
	}
	stack_to_stack(temp_stack_a, stacks[a]);
	stack_to_stack(temp_stack_b, stacks[b]);
	ft_printf("---------\na\tb\n");
/*

	int		a_size;
	int		b_size;
	int		i;

	a_size = ft_lstsize(stacks[a]);
	b_size = ft_lstsize(stacks[b]);
	i = a_size;
	if (b_size > i)
		i = b_size;
	a_iterator = stacks[a];
	b_iterator = stacks[b];
	while (i >= 1)
	{
		if (i <= a_size)
		{
			ft_printf("%d", *(int*)a_iterator->content);
			a_iterator = a_iterator->next;
		}
		ft_printf("\t");
		if (i-- <= b_size)
		{
			ft_printf("%d", *(int*)b_iterator->content);
			b_iterator = b_iterator->next;
		}
		ft_printf("\n");
	}
	ft_printf("---------\na\tb\n");*/
}

// Pops the stack completely over to the other stack, reversing the order
void	stack_to_stack(t_stack *stack_a, t_stack *stack_b)
{
	void	*temp_content;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	temp_content = pop(stack_a);
	while (temp_content != NULL)
	{
		push(stack_b, temp_content);
		temp_content = pop(stack_a);
	}
}

int		get_stack_size(t_stack *stack)
{
	t_stack	*temp_stack;
	int i;

	if (stack == NULL)
		return (-1);
	if (peek(stack) == NULL)
		return (0);
	temp_stack = new_stack();
	if (temp_stack == NULL)
		return -1;
	i  = 0;
	while (peek(stack) != NULL)
	{
		i++;
		push(temp_stack, pop(stack));
	}
	stack_to_stack(temp_stack, stack);
	del_stack(&temp_stack, NULL);
	return (i);
}