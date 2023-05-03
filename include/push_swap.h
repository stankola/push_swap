/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:21:36 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/02 15:21:37 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 
# include "libft.h"
# include "stack.h"
# include "ring.h"

typedef struct	s_vertex
{
	struct s_vertex	*parent;
	void			*parent_edge;
	void			*content;
}					t_vertex;

typedef struct	s_queue
{
	t_list		*head;
	t_list		*tail;
}				t_queue;

typedef struct	s_ps_stacks
{
	t_stack		*a;
	t_stack		*b;
	int			a_size;
	int			b_size;
	int			min;
	int			max;
}				t_ps_stacks;


enum		e_stacks {a, b};

int			is_sorted(t_stack *stack);

void		print_stacks(t_stack *const stacks[]);

void		print_rings(t_ring *rings[]);

int			countwords(char *strarr[]);


/*
t_list		*clone_stack(t_list const *stack);

t_list		**clone_stacks(t_list const *stacks[]);

int			count_inversions(t_list const *stack);

int			measure_disorder(t_list const *stack);

int			inverted_measure_disorder(t_list const *stack);

int			is_sorted(t_list *const stacks[]);

t_queue		*ft_queuenew(void);

void		ft_enqueue(t_queue**, void*);

void		*ft_dequeue(t_queue**);

void		ft_queueclear(t_queue**, void (*)(void*));

int			ft_queueisempty(t_queue *q);

t_vertex	*ft_vertnew(void *content, t_vertex *parent, void *parent_edge);

int			ft_verteq(t_vertex *v1, t_vertex *v2, int (*eqf)(void*, void*));

t_list		*ft_vertpath(t_vertex *v);

void		ft_vertdel(t_vertex **v, void(*del_content)(void*), void(*del_edge)(void*));

char		*breadth_first_search(t_list *stacks[]);
*/
#endif