/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:12:48 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/03 19:12:49 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int		is_sorted(t_list *const stacks[])
{
	int				prev;
	t_list const	*a_iterator;

	if (stacks[b] != NULL)
		return (0);
	if (stacks[a] == NULL && stacks[b] == NULL)
		return (1);
	a_iterator = stacks[a];
	while (a_iterator->next != NULL)
	{
		prev = *(int*)a_iterator->content;
		a_iterator = a_iterator->next;
		if (prev > *(int*)a_iterator->content)
			return (0);
	}
	return (1);
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

static void	chexecute(t_list *stacks[], t_queue *commands)
{
	int	*command;
	
	command = (int*)ft_dequeue(&commands);
	while (command != NULL)
	{
		if (*command == ps_sa || *command == ps_ss)
			swap(&stacks[a]);
		if (*command == ps_sb || *command == ps_ss)
			swap(&stacks[b]);
		if (*command == ps_pa)
			push(&stacks[a], &stacks[b]);
		if (*command == ps_pb)
			push(&stacks[b], &stacks[a]);
		if (*command == ps_ra || *command == ps_rr)
			rotate(&stacks[a]);
		if (*command == ps_rb || *command == ps_rr)
			rotate(&stacks[b]);
		if (*command == ps_rra || *command == ps_rrr)
			reverse_rotate(&stacks[a]);
		if (*command == ps_rrb || *command == ps_rrr)
			reverse_rotate(&stacks[b]);
		free(command);
		command = (int*)ft_dequeue(&commands);
	}
}

//TODO: File input to stdin???
int	main(int argc, char *argv[])
{
	t_list	**stacks;
	int		i;
	int		*iptr;
	char	*read_bfr;
	t_queue	*commands;

	if (argc <= 1)
		return (1);
	commands = NULL;
	stacks = malloc((b + 1) * sizeof(t_list*));
	i = argc - 1;
	stacks[a] = NULL;
	stacks[b] = NULL;
	while(i > 0)
	{
		iptr = malloc(sizeof(int));
		*iptr = ft_atoi(argv[i--]);	// TODO: Error handlng and detection: Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.
		ft_lstadd_front(&stacks[a], ft_lstnew(iptr));
	}
	stacks[b] = NULL;

	read_bfr = malloc (sizeof(char) * 5);
	while (1)
	{
		read(STDIN_FILENO, read_bfr, 5);
		iptr = malloc(sizeof(int));
		*iptr = string_to_command(read_bfr);
		if (!(ps_sa <= *iptr && *iptr <= ps_rrr))
			break;
		ft_enqueue(&commands, iptr);
	}
	free (read_bfr);		// these can be deleted to save lines.
	free (iptr);
	chexecute(stacks, commands);
	print_stacks(stacks);		// TESTING
	if (is_sorted(stacks))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	
	system("Leaks checker");
	return (1);
}
