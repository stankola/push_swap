#include "libft.h"

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
	value = *str++ - '0';
	while (ft_isdigit(*str))
	{
		value = value * 10 + *str - '0'; // TODO: Overflow detection
		str++;
	}
	if (*str == '\0')
		return (1);
	return (0);
}
