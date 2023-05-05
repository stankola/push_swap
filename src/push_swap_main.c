//TODO header

#include "push_swap.h"
#include "push_swap_operations.h"
#include "libft.h"
#include "sorting_algorithms.h"
#include "ft_math.h"

static int	*args_to_int_array(int argc, char *argv[])
{
	int		*iarr;
	int		i;

	iarr = malloc(sizeof(int) * argc);
	if (iarr == NULL)
		return (NULL);
	i  = 0;
	while(i < argc)
	{
		if (!ft_isinteger(argv[i]))
		{
			free(iarr);
			return (NULL);
		}
		iarr[i] = ft_atoi(argv[i]);
		i++;
	}
	return (iarr);
}

static int	check_duplicates(int iarr[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (++j < size)
		{
			if (iarr[i] == iarr[j])
				return (1);
		}
		i++;
	}
	return (0);
}

t_stack	**get_main_stacks(int *iarr, int size)
{
	t_stack	**stacks;
	int		i;

	stacks = malloc((b + 1) * sizeof(t_stack*));
	if (stacks == NULL)
		return (NULL);
	stacks[a] = ft_new_stack();
	stacks[b] = ft_new_stack();
	if (stacks[a] == NULL || stacks[b] == NULL)
	{
		free(stacks[a]);
		free(stacks[b]);
		free(stacks);
		return (NULL);
	}
	i = size - 1;
	while (0 <= i)
		ft_push(stacks[a], &iarr[i--]);
	return (stacks);
}

t_ring	**get_main_rings(int *iarr, int size)
{
	t_ring	**rings;
	int		i;

	rings = malloc((b + 1) * sizeof(t_ring*));
	if (rings == NULL)
		return (NULL);
	rings[a] = NULL;
	rings[b] = NULL;
	i = size - 1;
	while (0 <= i)
		ring_add(&rings[a], &iarr[i--]);
	return (rings);
}


void	print_command_stack(t_stack *command_stack)
{
	int		*iptr;
	t_stack	*temp_stack;

	temp_stack = ft_new_stack();
	stack_to_stack(command_stack, temp_stack);
	while (ft_peek(temp_stack) != NULL)
	{
		iptr = (int*)ft_pop(temp_stack);
		ft_printf("%s", command_to_string(*iptr));
		free(iptr);
		iptr = NULL;
	}
	ft_del_stack(&temp_stack, NULL);
}


int		*get_ptr_to_next_min_value(int iarr[], int cur_min, int size)
{
	int	next_min;
	int	i;
	int	*iptr;

	i = 0;
	next_min = INT_MAX;
	while (i < size)
	{
		if (iarr[i] < next_min && iarr[i] > cur_min)
		{
			next_min = iarr[i];
			iptr = &(iarr[i]);
		}
		i++;
	}
	return (iptr);
}

void	normalize_array(int iarr[], int size)
{
	int	**iptr_arr;
	int	i;
	int	*current_min;

	if (size <= 0)
		return ;
	iptr_arr = malloc(sizeof(int*) * size);
	if (iptr_arr == NULL)
		return ;
	current_min = get_ptr_to_next_min_value(iarr, INT_MIN, size);
	iptr_arr[0] = current_min;
	i = 1;
	while (i < size)
	{
		current_min = get_ptr_to_next_min_value(iarr, *current_min, size);
		iptr_arr[i++] = current_min;
	}
	while (--i >= 0)
	{
		*(iptr_arr[i]) = i;
	}
	free(iptr_arr);
}

int	main(int argc, char *argv[])
{
//	t_stack	**stacks;
	t_ring	**rings;
	t_stack	*command_stack;
	int		*iarr;
	char	**strarr;

	// Argument parsing

	if (argc <= 1)
		return (1);
	if (argc == 2)
	{
		strarr = ft_split(argv[1], ' ');
		argc = countwords(strarr) + 1;
	}
	else
		strarr = &argv[1];
	
	iarr = args_to_int_array(argc - 1, strarr);
	if (iarr == NULL || check_duplicates(iarr, argc - 1))
	{
		ft_printf("Error\n"); // TODO: This has to be printed in stderr!
		free(iarr);
		return (0);
	}

	// Arguments parsed
	normalize_array(iarr, argc - 1);

/*	// Normalized array print test:
	for (int j = 0; j < argc - 1; j++)
		ft_printf("%d\n", iarr[j]);
	return (0);
*/
//	stacks = get_main_stacks(iarr, argc - 1);
	rings = get_main_rings(iarr, argc - 1);
//	print_stacks(stacks);
//	print_rings(rings);
//	ft_printf("---------SORTING STARTING----------\n");
	if (rings != NULL)
	{
//		command_stack = insertion_sort(stacks);
//		command_stack = merge_sort(stacks);
		command_stack = ring_radix_sort(rings, argc - 1);
//		ft_printf("---------SORTED----------\n");
		print_command_stack(command_stack);
//		print_stacks(stacks);
		ft_del_stack(&command_stack, NULL);
//		ft_del_stack(&stacks[a], NULL);
//		ft_del_stack(&stacks[b], NULL);
//		free(stacks);
	}
	free(iarr);
	return (1);
}
