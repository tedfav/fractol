/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:31:06 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/13 17:16:37 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	while (*alst != NULL)
	{
		tmp = *alst;
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(tmp);
	}
	*alst = NULL;
}
