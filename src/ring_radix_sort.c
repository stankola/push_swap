// TODO  header

#include "push_swap.h"
#include "push_swap_operations.h"
#include "stack.h"
#include "ring.h"
#include "sorting_algorithms.h"
#include "ft_math.h"
#include "libft.h" // TEST

static int		get_digit_at(int value, int position)
{
	return (value / ft_pow_pos(10, position) % 10);
}

static void	sorting_step(t_stack *stacks[], t_stack *commands, int radix)
{
	int	i;
	int	j;
	int	a_rad;

	i = 0;
	if (ft_peek(stacks[b]) == NULL)
		i += execute(stacks, commands, ps_pa);
	// for (int i = 0; max >> i > 0; i++) {do stuff}
	while (ft_peek(stacks[a]) != NULL)
	{
		a_rad = get_digit_at(*(int*)ft_peek(stacks[a]), radix);
		j = 0;
		while (j < i)
		{
			ft_printf("Comparing %d and %d\n", *(int*)ft_peek(stacks[b]), a_rad);
			if (get_digit_at(*(int*)ft_peek(stacks[b]), radix) <= a_rad)
				break;
			j += execute(stacks, commands, ps_rrb);
		}
		i += execute(stacks, commands, ps_pa);
//		print_stacks(stacks);
	}
}

// For positive values
t_ring	*ring_radix_sort(t_ring *rings[])
{
	t_stack	*commands;
	int		radix;

	if (rings == NULL)
		return (NULL);
	commands = ft_new_stack();
	if (commands == NULL)
		return (NULL);
	radix = 0;
	sorting_step(rings, commands, radix);
	return (commands);
}