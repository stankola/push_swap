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

enum		e_commands {ps_sa, ps_sb, ps_ss, ps_pa, ps_pb, ps_ra, ps_rb, ps_rr, ps_rra, ps_rrb, ps_rrr};

enum		e_stacks {a, b};

void		delstacks(t_list *stacks[]);

void		execute(t_stack *stacks[], t_stack *command_stack, int command);

char		*command_to_string(int command);

void		del_int_ptr(int *iptr);

void		ps_swap(t_stack *stack);

void		ps_push(t_stack *stack_a, t_stack *stack_b);

void		ps_rotate(t_stack *stack);

void		ps_reverse_rotate(t_stack *stack);

int			compare_stacks(t_list *stacks_1[], t_list *stacks_2[]);

/* stack_functions.c TODO: consider moving to own header file */
int			is_sorted(t_stack *stack);

void		print_stacks(t_stack *const stacks[]);

void		stack_to_stack(t_stack *stack_a, t_stack *stack_b);

int			get_stack_size(t_stack *stack);

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

/*
 stack size = 1: vertices = 2, edges = 24
 stack size = 2: vertices = 2 + 2 + 2 = 6, edges = 12 * 6 = 72
 stack size = 3: vertices = 6 + 6 + 6 + 6 = 24, edges = 24 * 12 = 288
 stack size = 4: vertices = 24 + 24 + 24 + 24 + 24 = 24 * 5 = 120, edges = 120 * 12 = 1440
 stack size = n: vertices = n

n! 

1
2
3 4

1
3
2 4


1
2 3

2
1 3

1
3 2

2
3 1

3
1 2

3
2 1

  1
2 3

  1
3 2

  2
1 3

  2
3 1

  3
1 2

  3
2 1

*/