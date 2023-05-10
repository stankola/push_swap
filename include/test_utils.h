#ifndef TEST_UTILS_H
# define TEST_UTILS_H
# include "stack.h"
# include "ring.h"

void	print_stacks(t_stack *const stacks[]);

void	print_binary(int value, int padding);

void	print_rings(t_ring *rings[]);

#endif