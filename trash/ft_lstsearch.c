/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsankola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:55:50 by tsankola          #+#    #+#             */
/*   Updated: 2023/01/05 17:55:51 by tsankola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_lstsearch(t_list *lst, void *comparee, int (*matcher)(void*, void*))
{
	if (lst == NULL)
		return (NULL);
	if ((*matcher)(comparee, lst->content))
		return (lst->content);
	return (ft_lstsearch(lst->next, comparee, (*matcher)));
}
