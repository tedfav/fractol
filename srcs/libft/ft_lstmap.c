/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:37:39 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/15 15:06:24 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;
	t_list	*prev;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		prev = new;
		new = f(lst);
		if (new == NULL)
		{
			ft_lstdel(&begin, &ft_del_content);
			return (NULL);
		}
		prev->next = new;
		lst = lst->next;
	}
	return (begin);
}
