#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"		// To be included in libft.h
#include "sorting_algorithms.h"

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
	return stacks;
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

int	main(int argc, char *argv[])
{
	t_stack	**stacks;
	t_stack	*command_stack;
	int		*iarr;
	char	**strarr;

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
	stacks = get_main_stacks(iarr, argc - 1);
	if (stacks != NULL)
	{
		command_stack = insertion_sort(stacks);
//		command_stack = merge_sort(stacks);
		print_command_stack(command_stack);
		ft_del_stack(&command_stack, NULL);
		ft_del_stack(&stacks[a], NULL);
		ft_del_stack(&stacks[b], NULL);
		free(stacks);
	}
	free(iarr);
	return (1);
}
