/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:12:44 by tsankola          #+#    #+#             */
/*   Updated: 2023/03/20 17:12:45 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SORTING_ALGORITHMS_H
# define SORTING_ALGORITHMS_H
# include "libft.h"
# include "stack.h"
void	naive_sort(t_stack *stacks[]);

t_stack	*insertion_sort(t_stack *stacks[]);

t_stack	*merge_sort(t_stack *stacks[]);

#endif