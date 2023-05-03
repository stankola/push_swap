// TODO: header

#include "push_swap.h"
#include "push_swap_operations.h"
#include "libft.h"
#include <stdio.h> // TESTING

// Executes command on stacks and pushes it into command_stack. Returns 0 on
// succesful operation, 1 otherwise.
int	execute(t_stack *stacks[], t_stack *command_stack, int command)
{
	int	*iptr;

	ft_printf("%s\n", command_to_string(command));
	if (stacks == NULL || stacks[a] == NULL || stacks[b] == NULL ||
		command_stack == NULL || command < ps_sa || command > ps_rrr)
		return (0);
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
	print_stacks(stacks);
	getchar(); // TESTING
	return (1);
}

int	ring_execute(t_ring *rings[], t_stack *command_stack, int command, unsigned int repeat)
{
	int	*iptr;

	if (repeat == 0)
		return (0);
	ft_printf("%s\n", command_to_string(command));	// TESTING
	if (rings == NULL || command_stack == NULL || command < ps_sa || command > ps_rrr)
		return (0);
	if (command == ps_sa || command == ps_ss)
		ring_ps_swap(rings[a]);
	if (command == ps_sb || command == ps_ss)
		ring_ps_swap(rings[b]);
	if (command == ps_pa)
		ring_ps_push(rings[a], rings[b]);
	if (command == ps_pb)
		ring_ps_push(rings[b], rings[a]);
	if (command == ps_ra || command == ps_rr)
		ring_ps_rotate(rings[a]);
	if (command == ps_rb || command == ps_rr)
		ring_ps_rotate(rings[b]);
	if (command == ps_rra || command == ps_rrr)
		ring_ps_reverse_rotate(rings[a]);
	if (command == ps_rrb || command == ps_rrr)
		ring_ps_reverse_rotate(rings[b]);
	iptr = malloc(sizeof(int));
	*iptr = command;
	if (iptr != NULL)
		ft_push(command_stack, iptr);
	print_rings(rings);	// TESTING
	getchar(); // TESTING
	return (1 + ring_execute(rings, command_stack, command, repeat - 1));
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