/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkoverflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:50:24 by tsankola          #+#    #+#             */
/*   Updated: 2023/03/24 13:50:58 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#ifndef INT_MAX
# define INT_MAX 2147483647
#endif
#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

int	ft_chkovrflw_add(int x, int y)
{
	if (x > 0 && y > INT_MAX - x)
		return (1);
	if (x < 0 && y < INT_MIN - x)
		return (1);
	return (0);
}

int	ft_chkovrflw_mlt(int x, int y)
{
	if ((y == -1 && x == INT_MIN) || (x == -1 && y == INT_MIN))
		return (1);
	if (y != 0 && x > INT_MAX / y)
		return (1);
	if (y != 0 && x < INT_MIN / y)
		return (1);
	return (0);
}
