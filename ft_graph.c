/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:53:19 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/04 11:53:19 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft.h"
#include <stdio.h> // TESTING PURPOSES

t_vertex	*ft_vertnew(void *content, t_vertex *parent, void *parent_edge)
{
	t_vertex	*vertex;

	if (content == NULL || (parent == NULL && parent_edge != NULL) || (parent != NULL && parent_edge == NULL))
		return (NULL);
	vertex = malloc(sizeof(t_vertex));
	if (vertex == NULL)
		return (NULL);
	vertex->parent = parent;
	vertex->content = content;
	vertex->parent_edge = parent_edge;
//	fprintf(stderr, "Vertex %p created content %p parent %p edge %p\n", vertex, content, parent, parent_edge);
	return (vertex);
}

int		ft_verteq(t_vertex *v1, t_vertex *v2, int (*eqf)(void*, void*))
{
	if (eqf == NULL)
		exit(EXIT_FAILURE);
	if (v1 == NULL && v2 == NULL)
		return (1);
	if ((v1 == NULL && v2 != NULL) || (v1 != NULL && v2 == NULL))
		return (0);
	return (eqf(v1->content, v2->content));
}

t_list	*ft_vertpath(t_vertex *v)		// Not used?
{
	t_list	*l;
	t_list	*l2;

	if (v->parent == NULL)
		return (NULL);
	l = ft_lstnew(v->parent_edge);
	l2 = ft_vertpath(v->parent);
	if (l2 != NULL)
		ft_lstadd_front(&l, l2);
	return (l);
}

void	ft_vertdel(t_vertex **v, void(*del_content)(void*), void(*del_edge)(void*))
{
	if (v == NULL)
		return ;
	(*v)->parent = NULL;
	if (del_edge != NULL)
		del_edge((*v)->parent_edge);
	(*v)->parent_edge = NULL;
	if (del_content != NULL)
		del_content((*v)->content);
	(*v)->content = NULL;
	free(*v);
	*v = NULL;
}

/* TESTING STUFF BELOW */
/*
int		ft_icmp(int *i1, int *i2)
{
	return (*i1 == *i2);
}

int	main(void)
{
	t_vertex	*v1;
	t_vertex	*v2;
	t_vertex	*v3;

	int			*iptr1;
	int			*iptr2;
	int			*iptr3;

	iptr1 = malloc(sizeof(int));
	*iptr1 = 1;
	iptr2 = malloc(sizeof(int));
	*iptr2 = 2;
	iptr3 = malloc(sizeof(int));
	*iptr3 = 3;
	fprintf(stderr, "mallocs ok\n");

	v1 = ft_vertnew(iptr1, NULL, NULL);
	v2 = ft_vertnew(iptr2, v1, "one");
	v3 = ft_vertnew(iptr3, v2, "two");
	fprintf(stderr, "vertices created ok\n");

	t_list	*path = ft_vertpath(v3);
	fprintf(stderr, "path ok\n");
	t_list	*pi = path;
	while (pi != NULL)
	{
		fprintf(stderr, "%s ", pi->content);
		pi = pi->next;
	}
	fprintf(stderr, "\n");

	int		*iptr4;

	iptr4 = malloc(sizeof(int));
	*iptr4 = 2;
	t_vertex	*v4;
	v4 = ft_vertnew(iptr4, NULL, NULL);

	if (ft_verteq(v2, v4, (int (*)(void *, void *))ft_icmp))
		fprintf(stderr, "equality comparison with same numbers ok\n");
	if (!ft_verteq(v2, v3, (int (*)(void *, void *))ft_icmp))
		fprintf(stderr, "equality comparison with diff numbers ok\n");
	ft_vertdel(&v1, (void(*)(void*))del_int_ptr);
	ft_vertdel(&v2, (void(*)(void*))del_int_ptr);
	ft_vertdel(&v3, (void(*)(void*))del_int_ptr);
	ft_vertdel(&v4, (void(*)(void*))del_int_ptr);
	system("Leaks grp");
	return (1);
}*/