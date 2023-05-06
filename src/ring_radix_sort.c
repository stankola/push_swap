// TODO  header

#include "push_swap.h"
#include "push_swap_operations.h"
#include "stack.h"
#include "ring.h"
#include "sorting_algorithms.h"
#include "libft.h" // TEST
#include <stdio.h> // TEST

/* For normalized values, LSD radix sort would be ideal to ensure even 
 * distribution of buckets (I think). 
 * Idea:
 * 1. divide odds and evens
 * 2. divide by next bit... How does that work?
 */

// Sort 0's right and 1's left (smaller ones right, bigger ones left)
// executes size actions
// complexity: O(n)
static void base_step(t_ring *rings[], t_stack *commands, unsigned int size)
{
	unsigned int	radix;
	unsigned int	i;
	unsigned int	push_count;

	i = 0;
	radix = 1;
	push_count = 0;
//	ft_printf("base step size %d\n", size);
	// Could this be optimized using the knowledge that we have at max size / 2 (+ 1?) values to move?
	// Perhaps not, rotating does keep things in order. But we cannot expect any useful order so nevermind.
	// Answer is: yes.
	// The impact is veeeeery slight. If the last number is odd, then there is no impact.
	while (i++ < size && push_count < (size / 2) + (size % 2))
//	while (i++ < size)
	{
		if (!(*(int*)rings[a]->content & radix))
		{
			ring_execute(rings, commands, ps_pb, 1);
			push_count++;
		}
		else
			ring_execute(rings, commands, ps_ra, 1);
	}
}

// Sorting, theoretically executes min size, max 2 * size actions.
// In practice, will execute 3/2 * size actions.
// Complexity: O(n)
static void	sorting_step(t_ring *rings[], t_stack *commands, unsigned int radix)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	push_a_count;
	unsigned int	push_b_count;

	push_a_count = 0;
	push_b_count = 0;
	i = 0;
	// This could be optimized using the knowledge that we have at max size / 2 (+ 1?) values to move
	// Another improvement would be to peek inside the ring and rotate in the direction of the closest value to push
	i = get_ring_size(rings[a]);
	j = get_ring_size(rings[b]);
	while (i-- > 0)
		if (!(*(int*)rings[a]->content & radix))
		{
			ring_execute(rings, commands, ps_pb, 1);
			push_a_count++;
		}
		else if ((i == 0) && push_a_count > 0)	// Optimization. For 100 numbers the impact was 2 moves, ugh...
		{
			ring_execute(rings, commands, ps_rr, 1);
			push_a_count--;
		}
		else
			ring_execute(rings, commands, ps_ra, 1);
	ring_execute(rings, commands, ps_rb, push_a_count);
//	ft_printf("====A OK ====\n");
	while (j-- > 0)
	{
		if (*(int*)rings[b]->content & radix)
		{
			ring_execute(rings, commands, ps_pa, 1);
			push_b_count++;							// Not used
		}
		else
			ring_execute(rings, commands, ps_rb, 1);
	}
//	ft_printf("====B OK ====\n");
}

// Executes size / 2 actions
// Complexity O(n)
static void	final_step(t_ring *rings[], t_stack *commands)
{
	unsigned int	i;

	i = get_ring_size(rings[b]);
	ring_execute(rings, commands, ps_pa, i);
}


// For positive values, assuming normalized values (ie. 0,1,2,3,4,5,6...)
t_stack	*ring_radix_sort(t_ring *rings[], unsigned int size)
{
	t_stack			*commands;
	unsigned int	radix;

//	ft_printf("ring radix sort\n");
	if (rings == NULL)
		return (NULL);
	commands = ft_new_stack();
	if (commands == NULL)
		return (NULL);
//	ft_printf("====START====\n");
	base_step(rings, commands, size);	// O(n)
//	ft_printf("====BASED====\n");
//	print_rings(rings);
	radix = 2;
	while (radix < size)
	{	// Runs log2(n) times
//		ft_printf("====ROUND %d====\n", radix);
		sorting_step(rings, commands, radix);	// o(n)
		radix <<= 1;
	}
//	ft_printf("====SORTD====\n");
//	print_rings(rings);
	final_step(rings, commands);	// o(n)
//	ft_printf("====FINAL====\n");
//	print_rings(rings);
	return (commands);
}