/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:22:57 by tsankola          #+#    #+#             */
/*   Updated: 2023/05/10 13:22:59 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ring.h"
#include "stdlib.h"

int	get_ring_size(t_ring *ring)
{
	t_ring	*temp_ring;
	int		i;

	if (ring == NULL)
		return (0);
	temp_ring = ring->next;
	i = 1;
	while (temp_ring != ring)
	{
		i++;
		temp_ring = temp_ring->next;
	}
	return (i);
}
