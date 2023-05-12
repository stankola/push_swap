/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:58:51 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 12:58:52 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "push_swap_operations.h"
#include "libft.h"
#include "sorting_algorithms.h"
#include "ft_math.h"
#include <unistd.h>

static int	*str_array_to_int_array(int argc, char *argv[])
{
	int		*iarr;
	int		i;

	iarr = malloc(sizeof(int) * argc);
	if (iarr == NULL)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i]))
		{
			free(iarr);
			return (NULL);
		}
		iarr[i] = ft_atoi(argv[i]);
		i++;
	}
	return (iarr);
}

static t_ring	**get_main_rings(int *iarr, int size)
{
	t_ring	**rings;
	int		i;

	rings = malloc((b + 1) * sizeof(t_ring *));
	if (rings == NULL)
		return (NULL);
	rings[a] = NULL;
	rings[b] = NULL;
	i = size - 1;
	while (0 <= i)
		ring_add(&rings[a], &iarr[i--]);
	return (rings);
}

void	print_command_stack(t_stack *command_stack)
{
	char	*str;
	int		*iptr;
	t_stack	*temp_stack;

	temp_stack = ft_new_stack();
	stack_to_stack(command_stack, temp_stack);
	while (ft_peek(temp_stack) != NULL)
	{
		iptr = (int *)ft_pop(temp_stack);
		str = command_to_string(*iptr);
		ft_printf("%s", str);
		free(str);
		ft_push(command_stack, iptr);
	}
	ft_del_stack(&temp_stack, NULL);
}

void	sort_and_print(int iarr[], int size)
{
	t_ring	**rings;
	t_stack	*command_stack;

	normalize_array(iarr, size);
	rings = get_main_rings(iarr, size);
	if (rings != NULL)
	{
		command_stack = radix_sort(rings, size);
		print_command_stack(command_stack);
		ft_del_stack(&command_stack, &free);
		ring_del(&rings[a], NULL);
		ring_del(&rings[b], NULL);
		free(rings);
	}
}

int	main(int argc, char *argv[])
{
	int		*iarr;
	char	**strarr;
	int		size;
	int		i;

	if (argc == 2)
		strarr = ft_split(argv[1], ' ');
	else if (argc > 2)
		strarr = &argv[1];
	else
		return (1);
	size = countwords(strarr);
	iarr = str_array_to_int_array(size, strarr);
	if (iarr == NULL || is_duplicates(iarr, size))
		ft_fprintf(STDERR_FILENO, "Error\n");
	else
		sort_and_print(iarr, size);
	i = 0;
	while (argc == 2 && (strarr)[i] != NULL)
		free ((strarr)[i++]);
	if (argc == 2)
		free(strarr);
	free(iarr);
	return (1);
}
