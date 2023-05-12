/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:16:19 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 12:16:20 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_OPERATIONS_H
# define PUSH_SWAP_OPERATIONS_H
# include "stack.h"
# include "ring.h"

enum	e_ps_stacks {a, b};

enum	e_ps_commands
{
	ps_sa,
	ps_ra,
	ps_rra,
	ps_sb,
	ps_rb,
	ps_rrb,
	ps_ss,
	ps_pa,
	ps_pb,
	ps_rr,
	ps_rrr
};

int		execute(t_ring *rings[], t_stack *command_stack, int command,
			unsigned int repeat);

char	*command_to_string(int command);

int		string_to_command(char *str);

void	ps_swap(t_ring **ring);

void	ps_push(t_ring **ring_a, t_ring **ring_b);

void	ps_rotate(t_ring **ring);

void	ps_reverse_rotate(t_ring **ring);

#endif
