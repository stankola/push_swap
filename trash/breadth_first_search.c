/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:41:18 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/06 17:41:19 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h> // TESTING

char	*get_path_to_root(t_vertex *v)
{
	char	*commandstr;
	char	*pathstr;
	char	*tempstr;
	int i;

	if (v == NULL)
		return (NULL);
	pathstr = NULL;
	i = 0;
	while (v->parent_edge != NULL)		//TODO: If error???
	{
		commandstr = command_to_string(*(int*)v->parent_edge);
		tempstr = ft_strjoin(commandstr, pathstr);
		free(pathstr);
		free(commandstr);
		pathstr = tempstr;
		v = v->parent;
	}
	return (pathstr);
}

void	delstackvertex(t_vertex *v)
{
//	fprintf(stderr, "Deleting %p\n", v);
	ft_vertdel(&v, (void(*)(void*))delstacks, (void(*)(void*))del_int_ptr);
}

int		compare_stack_vertices(t_vertex *v1, t_vertex *v2)
{
	return (compare_stacks(v1->content, v2->content));
}

int	get_lowest_index(unsigned int array[], int size, unsigned int gt)
{
	int	i;
	int	mini;

	i = 0;
	mini = 0;
	while (i < size)
	{
		printf("what %d\n", array[i]);
		if (array[i] < array[mini])
		{
		printf("the\n");
			if(array[i] > gt)
			{
				mini = i;
				printf("hell\n");
			}
		}
		i++;
	}
	if (array[mini] > gt)
		return (mini);
	else
		return (-1);
}

int		generate_neighbours(t_queue **q, t_list *explored, t_vertex *v)
{
	int			command;
	int			*commandptr;
	t_list		**n_stacks;
	t_vertex	*new_v;
	int			neighbourcount;

	// shitty variables
	t_vertex		**neighbours = malloc((ps_rrr + 1) * sizeof(t_vertex*));
	unsigned int	neighbour_weight[11] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	command = ps_sa;
	neighbourcount = 0;
	while (command <= ps_rrr)
	{
		n_stacks = execute(v->content, command);
		commandptr = malloc(sizeof(int));
		*commandptr = command;
		new_v = ft_vertnew(n_stacks, v, commandptr);
//		printf("command %d stack %p vertex %p parent %p\n", command, n_stacks, new_v, new_v->parent);
//		print_stacks(n_stacks);
//		fprintf(stderr, "New neighbourh: %p %p %p %p", new_v, new_v->content, new_v->parent, new_v->parent_edge);
		if (ft_lstsearch(explored, new_v, (int(*)(void*, void*))compare_stack_vertices))
			delstackvertex(new_v);
		else
		{
//			ft_enqueue(q, new_v);	// TODO: what if vertnew fails?
			neighbours[command] = new_v;	// shitty line
			neighbour_weight[command] = measure_disorder(n_stacks[a]);	// shitty line
			neighbourcount++;	// shitty line
		}
		command++;
	}
	fprintf(stderr, "shit");
	/* Shit begins here */
	int i = -1;
	while (++i <= ps_rrr)
	{
		if (i == ps_pa || i == ps_pb)
			continue ;
		int min_i = get_lowest_index(neighbour_weight, ps_rrr + 1, -1);
		fprintf(stderr, "crap, min_i %d", min_i);
		if (min_i >= 0)
		{
			fprintf(stderr, "doo");
			ft_enqueue(q, (neighbours[min_i]));
			fprintf(stderr, "doo");
		}
	}
	fprintf(stderr, "poop");
//	free(neighbours[ps_pa]);
//	free(neighbours[ps_pb]);
	free(neighbours);
	/* Shit ends here */

	return (neighbourcount);
//	fprintf(stderr, "neighboursh ok\n");
}

char	*breadth_first_search(t_list *stacks[])
{
	t_queue		*q;			// queue of vertices
	t_list		*explored;	// list of vertices
	t_vertex	*v;
	char		*path;

	int exploredsize = 0;
	int qsize = 0;
//	unsigned long int			i;
	
	q = ft_queuenew();
	v = ft_vertnew(stacks, NULL, NULL);
	explored = NULL;
	ft_enqueue(&q, v);
	qsize++;
//	printf("comp1 %d\n", compare_stack_vertices(v, v));
//	printf("comp2 %p\n", ft_lstsearch(explored, v, (int (*)(void*, void*))compare_stack_vertices));
	printf("getting to work...\n");
//	i = 0;
	while (!ft_queueisempty(q))
	{
		fprintf(stderr, "queue state head %p tail %p\n", q->head, q->tail);
		v = ft_dequeue(&q);
		qsize--;
//		fprintf(stderr, "working on %d\n", *(int*)v->parent_edge);
		print_stacks(v->content);
		if (is_sorted(v->content))
		{
//			printf("goal found\n");
			break ;
		}
		if (ft_lstsearch(explored, v, (int (*)(void*, void*))compare_stack_vertices))
		{
//			fprintf(stderr, "freeing %p\n", v);
			ft_vertdel(&v, (void (*)(void*))delstacks, (void (*)(void*))del_int_ptr);
			continue ;
		}
		else
		{
			ft_lstadd_front(&explored, ft_lstnew(v));	// TODO: Error detection if lstnew fails
			exploredsize++;
		}
		qsize += generate_neighbours(&q, explored, v);
//		qsize += 12;
//		printf("%lu\n", i++);
	}
	printf("Work finished\n");
	printf("q size = %d  exploredsize = %d\n", qsize, exploredsize);
//	fprintf(stderr, "Goal ptr %p\n", v);
	path = get_path_to_root(v);
//	fprintf(stderr, "%s", path);
	fprintf(stderr, "path gotten\n");
	ft_queueclear(&q, (void(*)(void*))delstackvertex);
	fprintf(stderr, "queueclear ok\n");
//	fprintf(stderr, "Explored contents:\n");
//	for (t_list *t = explored; t != NULL; t = t->next)
//		fprintf(stderr, "loopy %p\n", t->content);
	ft_lstclear(&explored, (void(*)(void*))delstackvertex);
	fprintf(stderr, "exploredclear ok\n");
	ft_vertdel(&v, (void (*)(void*))delstacks, (void (*)(void*))del_int_ptr);
	return (path);
}
