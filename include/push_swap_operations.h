// TODO: header
#ifndef PUSH_SWAP_OPERATIONS_H
# define PUSH_SWAP_OPERATIONS_H
# include "stack.h"

enum		e_ps_commands {ps_sa, ps_sb, ps_ss, ps_pa, ps_pb, ps_ra, ps_rb,
			ps_rr, ps_rra, ps_rrb, ps_rrr};

void		execute(t_stack *stacks[], t_stack *command_stack, int command);

char		*command_to_string(int command);

int			string_to_command(char *str);

void		ps_swap(t_stack *stack);

void		ps_push(t_stack *stack_a, t_stack *stack_b);

void		ps_rotate(t_stack *stack);

void		ps_reverse_rotate(t_stack *stack);

#endif