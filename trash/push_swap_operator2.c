// TODO: header

#include "push_swap.h"
#include "push_swap_operations.h"
#include "libft.h"
#include "queue.h"
#include <stdio.h> // TESTING


typedef struct	s_operation		//MOve to header
{
	unsigned int	number;
	int				command;
	t_ring			**rings;	
}				t_operation;


static const t_queue	g_op_queue[] = {NULL, NULL};

// Executes command on stacks and pushes it into command_stack. Returns 0 on
// succesful operation, 1 otherwise.
int	execute(t_stack *stacks[], t_stack *command_stack, int command)
{
	int	*iptr;

//	ft_printf("%s\n", command_to_string(command));
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
//	print_stacks(stacks);
//	getchar(); // TESTING
	return (1);
}

static int	execute4real(t_ring *rings[], t_stack *command_stack, int command)
{
	if (command == ps_sa || command == ps_ss)
		ring_ps_swap(&rings[a]);
	if (command == ps_sb || command == ps_ss)
		ring_ps_swap(&rings[b]);
	if (command == ps_pa)
		ring_ps_push(&rings[b], &rings[a]);
	if (command == ps_pb)
		ring_ps_push(&rings[a], &rings[b]);
	if (command == ps_ra || command == ps_rr)
		ring_ps_rotate(&rings[a]);
	if (command == ps_rb || command == ps_rr)
		ring_ps_rotate(&rings[b]);
	if (command == ps_rra || command == ps_rrr)
		ring_ps_reverse_rotate(&rings[a]);
	if (command == ps_rrb || command == ps_rrr)
		ring_ps_reverse_rotate(&rings[b]);
	if (command_stack != NULL)
	{
		iptr = malloc(sizeof(int));
		*iptr = command;
		if (iptr != NULL)
			ft_push(command_stack, iptr);
	}
}

// e_ps_commands {ps_sa, ps_ra, ps_rra, ps_sb, ps_rb, ps_rrb, ps_ss,
//			ps_pa, ps_pb, ps_rr, ps_rrr};

static int combined_ops(int a, int b)
{
	if (a == ps_sa && b == ps_sb)
		return (ps_ss);
	else if (a == ps_ra && b == ps_rb)
		return (ps_rr);
	else if (a == ps_rra && b == ps_rrb)
		return (ps_rrr);
	else
		return (-1);
}

void	flush(void)
{
	int	a_ops[] = {0, 0, 0};	// swap, rotate, reverse rotate
	int	b_ops[] = {0, 0, 0};
	int	d_ops[] = {0, 0, 0};
	t_list	*a_i;
	t_list	*b_i;

	while (g_op_queue[a] != NULL || g_op_queue[b] != NULL)
	{
		if (g_op_queue[a] == NULL && g_op_queue[b] != NULL)
			execute4real(ft_dequeue(&g_op_queue[a]));
		else if (g_op_queue[a] != NULL && g_op_queue[b] == NULL)
			execute4real(ft_dequeue(&g_op_queue[b]));
		else if ((t_operation*)ft_queuepeek(g_op_queue[a])->command
			== (t_operation*)ft_queuepeek(g_op_queue[b])->command)
	}


	a_i = g_op_queue[a];
	b_i = g_op_queue[b];
	while (a_i != NULL && b_i != NULL)
	{
		if(a_i != NULL)
		{
			if (*(int*)a_i->content == ps_sa)
				a_ops[0]++;
			else if (*(int*)a_i->content == ps_ra)
				a_ops[1]++;
			else if (*(int*)a_i->content == ps_rra)
				a_ops[2]++;
			a_i = a_i->next;
		}
		if(b_i != NULL)
		{
			if (*(int*)b_i->content == ps_sb)
				b_ops[0]++;
			else if (*(int*)b_i->content == ps_rb)
				b_ops[1]++;
			else if (*(int*)b_i->content == ps_rrb)
				b_ops[2]++;
			b_i = b_i->next;
		}
	}
	d_ops[0] = a_ops[0] - b_ops[0];
	d_ops[1] = a_ops[1] - b_ops[1];
	d_ops[2] = a_ops[2] - b_ops[2];

	if d_ops[0] > 
}

int	ring_execute(t_ring *rings[], t_stack *command_stack, int command, unsigned int repeat)
{
	int					*iptr;
	static unsigned int	op_counter = 0;
	t_operation			*op;

	if (repeat == 0 || rings == NULL || command < ps_sa || command > ps_rrr)
		return (0);

	op = malloc(sizeof(t_operation));
	op->command = command;
	op->rings = rings;
	op->number = operation_counter++;
	if (command >= ps_ss && command <= ps_rrr)
	{
		flush();
		execute4real(op);
	}
	else if (command >= ps_sa && command <= ps_rra)
		ft_enqueue(g_op_queue[a], op);
	else if (command >= ps_sb && command <= ps_rrb)
		ft_enqueue(g_op_queue[b], op);

//	ft_printf("%s\n", command_to_string(command));	// TESTING
/*	if (command == ps_sa || command == ps_ss)
		ring_ps_swap(&rings[a]);
	if (command == ps_sb || command == ps_ss)
		ring_ps_swap(&rings[b]);
	if (command == ps_pa)
		ring_ps_push(&rings[b], &rings[a]);
	if (command == ps_pb)
		ring_ps_push(&rings[a], &rings[b]);
	if (command == ps_ra || command == ps_rr)
		ring_ps_rotate(&rings[a]);
	if (command == ps_rb || command == ps_rr)
		ring_ps_rotate(&rings[b]);
	if (command == ps_rra || command == ps_rrr)
		ring_ps_reverse_rotate(&rings[a]);
	if (command == ps_rrb || command == ps_rrr)
		ring_ps_reverse_rotate(&rings[b]);
*/	if (command_stack != NULL)
	{
		iptr = malloc(sizeof(int));
		*iptr = command;
		if (iptr != NULL)
			ft_push(command_stack, iptr);
	}
//	print_rings(rings);	// TESTING
//	getchar(); // TESTING
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