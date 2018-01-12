/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:30:46 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/15 10:37:05 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*last;

	if (!(elem = ft_create_elem(data)))
		return ;
	last = *begin_list;
	while (last->next != NULL)
		last = last->next;
	last->next = elem;
}
