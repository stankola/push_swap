// TODO header

#ifndef FT_MATH_H
# define FT_MATH_H
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif


int	ft_min(int a, int b);

int	ft_max(int a, int b);

int	ft_chkovrflw_add(int x, int y);

int	ft_chkovrflw_mlt(int x, int y);

int	ft_pow_pos(int x, int y);

#endif