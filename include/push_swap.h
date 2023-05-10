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
# include "stack.h"
# include "ring.h"

enum	e_ps_stacks {a, b};

int		check_duplicates(int iarr[], int size);

void	normalize_array(int iarr[], int size);

int		is_sorted(t_stack *stack);

int		countwords(char *strarr[]);

#endif