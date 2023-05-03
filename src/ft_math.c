// TODO header

#include "ft_math.h"

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

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}


int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

// For positive x values only. Returns -1 on overflow or error.
int	ft_pow_pos(int x, int y)
{
	int	result;

	result = 1;
	if (y < 0 && x == 0)
		return (-1);
	while (y-- > 0)
	{
		if (!ft_chkovrflw_mlt(result, x))
			result *= x;
		else
			return (-1);
	}
	return (result);
}