/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:12:44 by tsankola          #+#    #+#             */
/*   Updated: 2023/03/20 17:12:45 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SORTING_ALGORITHMS_H
# define SORTING_ALGORITHMS_H
# include "stack.h"
# include "ring.h"

typedef struct	s_ring_state
{
	t_ring				**rings;
	struct s_ring_state	*parent;
	int					visited;
	int					path_length;
	int					prev_command;
}				t_ring_state;

void			ring_state_del(t_ring_state *ring_state);

t_ring_state	*new_state(t_ring *rings[], t_ring_state *parent, int prev_cmd);

int				ring_state_eq(t_ring_state *state_a, t_ring_state *state_b);

t_stack			*radix_sort(t_ring *rings[], unsigned int size);

t_stack			*brute(t_ring *rings[]);

#endif