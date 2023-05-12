/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:24:30 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 12:24:34 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RING_H
# define RING_H

typedef struct s_ring
{
	struct s_ring	*next;
	struct s_ring	*prev;
	void			*content;
}				t_ring;

t_ring	*ring_new(void *content);

void	ring_add(t_ring **ring, void *content);

void	*ring_take(t_ring **ring);

void	ring_rotate(t_ring **ring);

void	ring_reverse_rotate(t_ring **ring);

int		get_ring_size(t_ring *ring);

#endif
