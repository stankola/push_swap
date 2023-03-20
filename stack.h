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

typedef struct	s_stack
{
	t_list	*head;
}				t_stack;

t_stack	*new_stack();

void	push(t_stack *stack, void *content);

void	*pop(t_stack *stack);

void	del_stack(t_stack **stack, void (*del)(void*));

#endif