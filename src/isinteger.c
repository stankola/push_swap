/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isinteger.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:49:49 by tsankola          #+#    #+#             */
/*   Updated: 2023/03/24 13:51:43 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_math.h"

int	ft_isinteger(char *str)
{
	int	value;
	int	sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	value = sign * (*(str++) - '0');
	while (ft_isdigit(*str))
	{
		if (ft_chkovrflw_mlt(value, 10)
			|| ft_chkovrflw_add(value * 10, sign * (*str - '0')))
			return (0);
		value = value * 10 + sign * (*str - '0');
		str++;
	}
	if (*str == '\0')
		return (1);
	return (0);
}
