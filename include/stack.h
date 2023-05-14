/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:40:52 by tsankola          #+#    #+#             */
/*   Updated: 2023/03/20 18:40:53 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STACK_H
# define STACK_H
# include "libft.h"

typedef struct s_stack
{
	t_list	*head;
}				t_stack;

t_stack	*ft_new_stack(void);

void	ft_push(t_stack *stack, void *content);

void	*ft_pop(t_stack *stack);

void	ft_del_stack(t_stack **stack, void (*del)(void*));

void	*ft_peek(t_stack *stack);

void	stack_to_stack(t_stack *stack_a, t_stack *stack_b);

int		get_stack_size(t_stack *stack);

t_stack	*stack_clone(t_stack *stack, void *(*f)(void *), void (*del)(void *));

#endif