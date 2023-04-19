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
		ft_push(command_stack, iptr);
}

// Returns NULL if ft_strdup fails
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
	return (ft_strdup(str));
}

int		string_to_command(char *str)
{
	int	command;

	command = -1;
	if (ft_strncmp(str, "sa", 2) == 0)
		command = ps_sa;
	else if (ft_strncmp(str, "sb", 2) == 0)
		command = ps_sb;
	else if (ft_strncmp(str, "ss", 2) == 0)
		command = ps_ss;
	else if (ft_strncmp(str, "pa", 2) == 0)
		command = ps_pa;
	else if (ft_strncmp(str, "pb", 2) == 0)
		command = ps_pb;
	else if (ft_strncmp(str, "rra", 3) == 0)
		command = ps_rra;
	else if (ft_strncmp(str, "rrb", 3) == 0)
		command = ps_rrb;
	else if (ft_strncmp(str, "rrr", 3) == 0)
		command = ps_rrr;
	else if (ft_strncmp(str, "ra", 2) == 0)
		command = ps_ra;
	else if (ft_strncmp(str, "rb", 2) == 0)
		command = ps_rb;
	else if (ft_strncmp(str, "rr", 2) == 0)
		command = ps_rr;
	return (command);
}

int		countwords(char *strarr[])
{
	int	i;

	i = 0;
	while (strarr[i] != NULL)
		i++;
	return (i);
}

/* TESTING MAIN */ /*
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
	stacks[a] = ft_new_stack();
	stacks[b] = ft_new_stack();
//	command_stack = ft_new_stack();
	while(i > 0)
	{
		iptr = malloc(sizeof(int));
		*iptr = ft_atoi(argv[i--]);
		printf("Pushing %p: %i\n", iptr, *iptr);
		ft_push(stacks[a], iptr);
	}
	print_stacks(stacks);
	command_stack = insertion_sort(stacks);
	print_command_stack(command_stack);

//	system("Leaks pusa");
	return (1);
}
*/