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
#include <stdlib.h>
#include <stdio.h>		// TESTING
#include "push_swap.h"
#include "sorting_algorithms.h"
#include "ft_printf.h"

void	execute(t_stack *stacks[], t_stack *command_stack, int command)
{
	int	*iptr;

	if (stacks == NULL || stacks[a] == NULL || stacks[b] == NULL ||
		command_stack == NULL || command < ps_sa || command > ps_rrr)
		return ;
	if (command == ps_sa || command == ps_ss)
		ps_swap(stacks[a]);
	if (command == ps_sb || command == ps_ss)
		ps_swap(stacks[b]);
	if (command == ps_pa)
		ps_push(stacks[a], stacks[b]);
	if (command == ps_pb)
		ps_push(stacks[b], stacks[a]);
	if (command == ps_ra || command == ps_rr)
		ps_rotate(stacks[a]);
	if (command == ps_rb || command == ps_rr)
		ps_rotate(stacks[b]);
	if (command == ps_rra || command == ps_rrr)
		ps_reverse_rotate(stacks[a]);
	if (command == ps_rrb || command == ps_rrr)
		ps_reverse_rotate(stacks[b]);
	iptr = malloc(sizeof(int));
	*iptr = command;
	if (iptr != NULL)
		push(command_stack, iptr);
}

char	*command_to_string(int command)
{
	char	*str;

	if (command == ps_sa)
		str = "sa\n";
	else if (command == ps_sb)
		str = "sb\n";
	else if (command == ps_ss)
		str = "ss\n";
	else if (command == ps_pa)
		str = "pa\n";
	else if (command == ps_pb)
		str = "pb\n";
	else if (command == ps_ra)
		str = "ra\n";
	else if (command == ps_rb)
		str = "rb\n";
	else if (command == ps_rr)
		str = "rr\n";
	else if (command == ps_rra)
		str = "rra\n";
	else if (command == ps_rrb)
		str = "rrb\n";
	else if (command == ps_rrr)
		str = "rrr\n";
	return (ft_strdup(str));	//possible malloc failure inside, returns NULL, should be ok, NULL is then returned upwards.
}

void	print_command_stack(t_stack *command_stack)
{
	int		*iptr;
	t_stack	*temp_stack;

	temp_stack = new_stack();
	stack_to_stack(command_stack, temp_stack);
	while (peek(temp_stack) != NULL)
	{
		iptr = (int*)pop(temp_stack);
		ft_printf("%s", command_to_string(*iptr));
		free(iptr);
		iptr = NULL;
	}
	del_stack(&temp_stack, NULL);
}
// TODO: Errors include: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.
static int	*args_to_int_array(int argc, char *argv[])
{
	int		*iarr;
	int		i;

	iarr = malloc(sizeof(int) * argc);
	if (iarr == NULL)
		return (NULL);
	i  = 0;
	while(i < argc)
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



/* TESTING MAIN */
int	main(int argc, char *argv[])
{
	t_stack	**stacks;
	t_stack *command_stack;
	int		i;
	int		*iptr;

	if (argc <= 1)
		return (1);
	i = argc - 1;
	stacks = malloc((b + 1) * sizeof(t_stack*));
	stacks[a] = new_stack();
	stacks[b] = new_stack();
//	command_stack = new_stack();
	while(i > 0)
	{
		iptr = malloc(sizeof(int));
		*iptr = ft_atoi(argv[i--]);
		printf("Pushing %p: %i\n", iptr, *iptr);
		push(stacks[a], iptr);
	}
	print_stacks(stacks);
/*	execute(stacks, command_stack, ps_pa);
	execute(stacks, command_stack, ps_pa);
	execute(stacks, command_stack, ps_ss);
	print_stacks(stacks);
	print_command_stack(command_stack);*/
	command_stack = insertion_sort(stacks);
	print_command_stack(command_stack);

//	system("Leaks pusa");
	return (1);
}

/* PRODUCTION MAIN */
int	main(int argc, char *argv[])
{
	t_stack	**stacks;
	t_stack *command_stack;
	int		i;
	int		*iptr;

	if (argc <= 1)
		return (1);
	i = argc - 1;
	stacks = malloc((b + 1) * sizeof(t_stack*));
	if (stacks == NULL)
		return (0);
	stacks[a] = new_stack();
	stacks[b] = new_stack();
	while(i > 0)
	{
		iptr = malloc(sizeof(int));
		*iptr = ft_atoi(argv[i--]);	// TODO: Error handlng and detection: Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.
		push(stacks[a], iptr);
	}
	command_stack = insertion_sort(stacks);
	print_command_stack(command_stack);
	return (1);
}
