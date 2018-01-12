/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:13:43 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/09 16:24:28 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!(dst = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
