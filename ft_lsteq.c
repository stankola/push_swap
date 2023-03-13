/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsteq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:31:05 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/04 16:31:06 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// TODO: Makefile addition

int	ft_lsteq(t_list *l1, t_list *l2, int (*eqf)(void*, void*))
{
	t_list	*l1_itr;
	t_list	*l2_itr;

	if (eqf == NULL)
		exit(EXIT_FAILURE);
	l1_itr = l1;
	l2_itr = l2;
	while (l1_itr != NULL && l2_itr != NULL && eqf(l1_itr->content, l2_itr->content))
	{
		l1_itr = l1_itr->next;
		l2_itr = l2_itr->next;
	}
	if (l1_itr == NULL && l2_itr == NULL)
		return (1);
	return (0);
}