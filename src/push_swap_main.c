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

static int	*args_to_int_array(int argc, char *argv[])
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

t_ring	**get_main_rings(int *iarr, int size)
{
	t_ring	**rings;
	int		i;

	rings = malloc((b + 1) * sizeof(t_ring*));
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
		iptr = (int*)ft_pop(temp_stack);
		str = command_to_string(*iptr);
		ft_printf("%s", str);
		free(str);
		ft_push(command_stack, iptr);
	}
	ft_del_stack(&temp_stack, NULL);
}

int	main(int argc, char *argv[])
{
	t_ring	**rings;
	t_stack	*command_stack;
	int		*iarr;
	char	**strarr;

	//TODO: Clean this parsing mess up
	if (argc <= 1)
		return (1);
	if (argc == 2)
	{
		strarr = ft_split(argv[1], ' ');
		argc = countwords(strarr) + 1;
	}
	else
		strarr = &argv[1];
	iarr = args_to_int_array(argc - 1, strarr);
	int i = 0;
	while (strarr[i] != NULL)
		free(strarr[i]);
	free (strarr);
	if (iarr == NULL || check_duplicates(iarr, argc - 1))
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		free(iarr);
		return (0);
	}
	// Arguments parsed
	normalize_array(iarr, argc - 1);
	// Normalized array print test:
	rings = get_main_rings(iarr, argc - 1);
//	print_rings(rings);
	if (rings != NULL)
	{
		command_stack = ring_radix_sort(rings, argc - 1);
		print_command_stack(command_stack);
		while(ft_peek(command_stack) != NULL)
			free(ft_pop(command_stack));
		ft_del_stack(&command_stack, NULL);

		while (rings[a] != NULL) 
			ring_take(&rings[a]);
		while (rings[b] != NULL)
			free(ring_take(&rings[b]));
	}
	free(iarr);
	return (1);
}
