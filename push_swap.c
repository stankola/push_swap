/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:21:26 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/02 15:21:28 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>		// TESTING
#include "push_swap.h"
#include "sorting_algorithms.h"
//#include "ft_printf.h"

// TODO NEXT:
// Shortest route problem, not sorting problem! (edit: maybe little sorting required ;)
// Should there be better data structure than linked list? Could try to do data structure independent traversal and replace if needed.

void	delstacks(t_list *stacks[])
{
	if (stacks == NULL)
		return ;
	ft_lstclear(&stacks[a], (void(*)(void*))del_int_ptr);
	ft_lstclear(&stacks[b], (void(*)(void*))del_int_ptr);
	free(stacks);
}

t_list	**execute(t_list *stacks[], int command)
{
	t_list	**result_stacks;

	result_stacks = clone_stacks((const t_list**)stacks);
	if (result_stacks != NULL)
	{
		if (command == ps_sa || command == ps_ss)
			swap(&result_stacks[a]);
		if (command == ps_sb || command == ps_ss)
			swap(&result_stacks[b]);
		if (command == ps_pa)
			push(&result_stacks[a], &result_stacks[b]);
		if (command == ps_pb)
			push(&result_stacks[b], &result_stacks[a]);
		if (command == ps_ra || command == ps_rr)
			rotate(&result_stacks[a]);
		if (command == ps_rb || command == ps_rr)
			rotate(&result_stacks[b]);
		if (command == ps_rra || command == ps_rrr)
			reverse_rotate(&result_stacks[a]);
		if (command == ps_rrb || command == ps_rrr)
			reverse_rotate(&result_stacks[b]);
	}
	return (result_stacks);
}

char	*command_to_string(int command)
{
	char	*str;

	if (command == ps_sa)
		str = "sa\n";
	else if (command == ps_sb)
		str = "sb\n";
	else if (command == ps_ss)
		str = "ss\n";
	else if (command == ps_pa)
		str = "pa\n";
	else if (command == ps_pb)
		str = "pb\n";
	else if (command == ps_ra)
		str = "ra\n";
	else if (command == ps_rb)
		str = "rb\n";
	else if (command == ps_rr)
		str = "rr\n";
	else if (command == ps_rra)
		str = "rra\n";
	else if (command == ps_rrb)
		str = "rrb\n";
	else if (command == ps_rrr)
		str = "rrr\n";
	return (ft_strdup(str));	//possible malloc failure inside, returns NULL, should be ok.
}

int	main(int argc, char *argv[])
{
	t_list	**stacks;
	int		i;
	int		*iptr;

	if (argc <= 1)
		return (1);
	i = argc - 1;
	stacks = malloc((b + 1) * sizeof(t_list*));
	stacks[a] = NULL;
	stacks[b] = NULL;
	while(i > 0)
	{
		iptr = malloc(sizeof(int));
		*iptr = ft_atoi(argv[i--]);	// TODO: Error handlng and detection: Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.
		ft_lstadd_front(&stacks[a], ft_lstnew(iptr));
	}
	insertion_sort(stacks);
//	fprintf(stderr, "Finding goal\n");
//	char *path = breadth_first_search(stacks);
//	printf("Printing goal\n");
//	printf("%s", path);
//	system("Leaks pusa");
	return (1);
}
