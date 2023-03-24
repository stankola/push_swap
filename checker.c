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

static void	chexecute(t_stack *stacks[], t_queue *commands)
{
	int	*command;
	
	command = (int*)ft_dequeue(&commands);
	while (command != NULL)
	{
		if (*command == ps_sa || *command == ps_ss)
			ps_swap(stacks[a]);
		if (*command == ps_sb || *command == ps_ss)
			ps_swap(stacks[b]);
		if (*command == ps_pa)
			ps_push(stacks[a], &stacks[b]);
		if (*command == ps_pb)
			ps_push(stacks[b], &stacks[a]);
		if (*command == ps_ra || *command == ps_rr)
			ps_rotate(stacks[a]);
		if (*command == ps_rb || *command == ps_rr)
			ps_rotate(stacks[b]);
		if (*command == ps_rra || *command == ps_rrr)
			ps_reverse_rotate(stacks[a]);
		if (*command == ps_rrb || *command == ps_rrr)
			ps_reverse_rotate(stacks[b]);
		free(command);
		command = (int*)ft_dequeue(&commands);
	}
}

//TODO: File input to stdin???
int	main(int argc, char *argv[])
{
	t_stack	**stacks;
	int		i;
	int		*iptr;
	char	*read_bfr;
	t_queue	*commands;

	if (argc <= 1)
		return (1);
	commands = NULL;
	stacks = malloc((b + 1) * sizeof(t_stack*));
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
