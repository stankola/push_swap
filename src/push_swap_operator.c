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

static void	execute4real(t_ring *rings[], int command)
{
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
}

int	execute(t_ring *rings[], t_stack *command_stack, int command,
	unsigned int repeat)
{
	int	*iptr;

	if (repeat == 0 || rings == NULL || command < ps_sa || command > ps_rrr)
		return (0);
	execute4real(rings, command);
	if (command_stack != NULL)
	{
		iptr = malloc(sizeof(int));
		*iptr = command;
		if (iptr != NULL)
			ft_push(command_stack, iptr);
	}
	return (1 + execute(rings, command_stack, command, repeat - 1));
}

// Translates command to a string. Returns NULL if ft_strdup fails
char	*command_to_string(int command)
{
	if (command == ps_sa)
		return (ft_strdup("sa\n"));
	else if (command == ps_sb)
		return (ft_strdup("sb\n"));
	else if (command == ps_ss)
		return (ft_strdup("ss\n"));
	else if (command == ps_pa)
		return (ft_strdup("pa\n"));
	else if (command == ps_pb)
		return (ft_strdup("pb\n"));
	else if (command == ps_ra)
		return (ft_strdup("ra\n"));
	else if (command == ps_rb)
		return (ft_strdup("rb\n"));
	else if (command == ps_rr)
		return (ft_strdup("rr\n"));
	else if (command == ps_rra)
		return (ft_strdup("rra\n"));
	else if (command == ps_rrb)
		return (ft_strdup("rrb\n"));
	else if (command == ps_rrr)
		return (ft_strdup("rrr\n"));
	return (NULL);
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
