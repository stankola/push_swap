/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:10 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 14:51:15 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "push_swap_operations.h"
#include "libft.h"

int	execute(t_ring *rings[], t_stack *command_stack, int command,
	unsigned int repeat)
{
	int	*iptr;

	if (repeat == 0)
		return (0);
//	ft_printf("%s\n", command_to_string(command));	// TESTING
	if (rings == NULL || command < ps_sa || command > ps_rrr)
		return (0);
	if (command == ps_sa || command == ps_ss)
		ps_swap(&rings[a]);
	if (command == ps_sb || command == ps_ss)
		ps_swap(&rings[b]);
	if (command == ps_pa)
		ps_push(&rings[b], &rings[a]);
	if (command == ps_pb)
		ps_push(&rings[a], &rings[b]);
	if (command == ps_ra || command == ps_rr)
		ps_rotate(&rings[a]);
	if (command == ps_rb || command == ps_rr)
		ps_rotate(&rings[b]);
	if (command == ps_rra || command == ps_rrr)
		ps_reverse_rotate(&rings[a]);
	if (command == ps_rrb || command == ps_rrr)
		ps_reverse_rotate(&rings[b]);
	if (command_stack != NULL)
	{
		iptr = malloc(sizeof(int));
		*iptr = command;
		if (iptr != NULL)
			ft_push(command_stack, iptr);
	}
//	print_rings(rings);	// TESTING
//	getchar(); // TESTING
	return (1 + execute(rings, command_stack, command, repeat - 1));
}

// Translates command to a string. Returns NULL if ft_strdup fails
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

int	string_to_command(char *str)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		return (ps_sa);
	else if (ft_strncmp(str, "sb", 2) == 0)
		return (ps_sb);
	else if (ft_strncmp(str, "ss", 2) == 0)
		return (ps_ss);
	else if (ft_strncmp(str, "pa", 2) == 0)
		return (ps_pa);
	else if (ft_strncmp(str, "pb", 2) == 0)
		return (ps_pb);
	else if (ft_strncmp(str, "rra", 3) == 0)
		return (ps_rra);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		return (ps_rrb);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		return (ps_rrr);
	else if (ft_strncmp(str, "ra", 2) == 0)
		return (ps_ra);
	else if (ft_strncmp(str, "rb", 2) == 0)
		return (ps_rb);
	else if (ft_strncmp(str, "rr", 2) == 0)
		return (ps_rr);
	return (-1);
}
