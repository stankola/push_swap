#include "push_swap.h"
#include "push_swap_operations.h"
#include "ft_math.h"
#include "sorting_algorithms.h"
#include "ring.h"		// Might be unnecessary if included in sorting_algorithms.h

/* Complexity: n/2 + 3n/4 + log2(n) * 3/2 * n (divide, 0. step, subsequent steps)
 * n = 100 => ~1150 moves
 * n = 500 => ~7350 moves
 * O(n log n)
 */

// Returns closest integer (rounded down) to log x of base y.
static int	ms_log(int x, int y)
{
	int	i;

	i = 0;
	while (ft_pow_pos(y, i) <= x)
		i++;
	return (i - 1);
}

// TODO: Consider size < 2
// TODO: Consider offset values when size is not a power of 2
static void	divide_step(t_ring *rings[], t_stack *command_stack, int size)
{
	int	i;

	i = 0;
	ft_printf("dividing size: %d\n", size);	// TEST
	while (i++ < size / 2)
		ring_execute(rings, command_stack, ps_sa, 1);
	print_rings(rings);		// TEST
}


// Takes max(left,right) (, pushes it left) and rotates for a_height+b_height times
static void merge_left(t_ring *rings[], t_stack *command_stack, int a_height, int b_height)
{
	ft_printf("left%d %d\n", a_height, b_height);	// TEST
	while (a_height > 0 || b_height > 0)
	{
		if (((a_height != 0 && b_height != 0)
			&& (*(int*)rings[a]->content > *(int*)rings[b]->content))
			|| (a_height == 0))
		{
			b_height--;
			ring_execute(rings, command_stack, ps_pb, 1);
		}
		else 
			a_height--;
		ring_execute(rings, command_stack, ps_ra, 1);
	}
}

static void merge_right(t_ring *rings[], t_stack *command_stack, int a_height, int b_height)
{
	ft_printf("right %d %d\n", a_height, b_height);
	while (a_height > 0 || b_height > 0)
	{
		if (((a_height != 0 && b_height != 0)
			&& (*(int*)rings[a]->content < *(int*)rings[b]->content))
			|| (b_height == 0))
			{
				a_height--;
				ring_execute(rings, command_stack, ps_pa, 1);
			}
			else 
				b_height--;
		ring_execute(rings, command_stack, ps_rb, 1);
	}
}

static void	sorting_step(t_ring *rings[], t_stack *command_stack, int step, int size)
{
	int	i;
	int	leftovers;

	i = 0;
	ft_printf("step %d\n", step);
	if (step == 0)
	{
		while (i++ < size / 4)
		{
			if (*(int*)rings[a]->content > *(int*)rings[a]->prev->content &&
				*(int*)rings[b]->content < *(int*)rings[b]->prev->content)
				ring_execute(rings, command_stack, ps_ss, 1);
			else if (*(int*)rings[a]->content > *(int*)rings[a]->prev->content)
				ring_execute(rings, command_stack, ps_sa, 1);
			else if (*(int*)rings[b]->content < *(int*)rings[b]->prev->content)
				ring_execute(rings, command_stack, ps_sb, 1);
			ring_execute(rings, command_stack, ps_rr, 2);
		}
		i = (--i) * 4;
		if (i < size)
		{
			// How to handle leftover values?
			// a.) Keep them at the end and merge in the final step
			// b.) Include them in the last set. Adds some overhead but 
			// perhaps it could be manageable. Size of the last set can be
			// calculated.
		}
	}

	while (i < size / power(2, step + 1))	// Perhaps <= to account for leftover values? Or another loop for them
	{
		if (i % 2 == 0)
		{
			merge_left(rings, command_stack, power(2, step), power(2, step));
			print_rings(rings);
		}
		else
		{
			merge_right(rings, command_stack, power(2, step), power(2, step));
			print_rings(rings);
		}
		i++;
	}
	leftovers = size % power(2, step + 1);
	ft_printf("%d values unhandled\n", leftovers);
//	int	right_leftovers;
//	int	left_leftovers;
	if (leftovers > 0)
	{
		if (step % 2 == 0)
			merge_right(rings, command_stack, leftovers - (leftovers / power(2, step)), 0);
		else
			merge_left(rings, command_stack, (leftovers / power(2, step)) * power(2, step), leftovers % power(2, step));
	}
}

t_stack	*merge_sort(t_ring *rings[])
{
	t_stack	*command_stack;
	int		size;
	int		step;

	if (rings == NULL)
		return (NULL);
	command_stack = ft_new_stack();
	if (command_stack == NULL)
		return (NULL);
	size = get_ring_size(rings[a]);
	// divide stack
	print_rings(rings);		// TEST
	divide_step(rings, command_stack, size);
	// while unsorted sort from 2^n to size, where n = 0, 1, 2, 3...
	ft_printf("Sorting ");		// TEST
	step = 0;
	while (ft_pow_pos(step, 2) < size)
	{
		sorting_step(rings, command_stack, step++, size);
		ft_printf("After Sorting\n");		// TEST
		print_rings(rings);
	}
	return (command_stack);
}