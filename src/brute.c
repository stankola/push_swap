/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:36:55 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/15 19:37:02 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "push_swap_operations.h"
#include "ring.h"
#include "stack.h"
#include "queue.h"
#include "sorting_algorithms.h"

static t_ring	**clone_rings(t_ring *rings[])
{
	t_ring	**clones;

	clones = malloc(sizeof(t_ring *) * (b + 1));
	if (clones == NULL)
		return (NULL);
	clones[a] = ring_clone(rings[a]);
	clones[b] = ring_clone(rings[b]);
	return (clones);
}

static t_stack	*get_command_stack(t_ring_state *state)
{
	t_stack	*commands;
	t_stack	*temp_stack;
	int		*iptr;

	if (state == NULL)
		return (NULL);
	commands = ft_new_stack();
	temp_stack = ft_new_stack();
	while (state->parent != NULL)
	{
		iptr = malloc(sizeof(int));
		*iptr = state->prev_command;
		ft_push(temp_stack, iptr);
		state = state->parent;
	}
	stack_to_stack(temp_stack, commands);
	ft_del_stack(&temp_stack, NULL);
	return (commands);
}

void create_child(int command, t_ring_state *state, t_queue *q[])
{
	t_ring_state	*t;

	t = new_state(clone_rings(state->rings), state, command);
	execute(t->rings, NULL, command, 1);
	if (queue_contains(q[0], (void *)t, (int(*)(void*,void*))ring_state_eq)
		|| queue_contains(q[1], (void *)t, (int(*)(void*,void*))ring_state_eq))
		ring_state_del(t);
	else
		ft_enqueue(&q[0], t);
}

// search space = (n + 1) * n!
t_stack	*brute(t_ring *rings[])
{
	t_ring_state	*cur_state;
	int				command;
	t_queue			**queues;
	t_stack			*commands;

	queues = ft_calloc(2, sizeof(t_queue *));
	cur_state = new_state(clone_rings(rings), NULL, -1);
	ft_enqueue(&queues[0], cur_state);
	while (1)
	{
		cur_state = (t_ring_state *)ft_dequeue(&queues[0]);
		if (cur_state->rings[b] == NULL && is_sorted(cur_state->rings[a]))
			break ;
		ft_enqueue(&queues[1], cur_state);
		command = ps_sa;
		while (command <= ps_rrr)
			create_child(command++, cur_state, queues);
	}
	commands = get_command_stack(cur_state);
	ft_queueclear(&queues[1], (void (*)(void *))ring_state_del);
	ft_queueclear(&queues[0], (void (*)(void *))ring_state_del);
	free(queues);
	return (commands);
}
