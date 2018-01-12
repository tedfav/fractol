/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:59:42 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/13 08:09:55 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sr;
	size_t			i;

	i = 0;
	dest = (unsigned char*)dst;
	sr = (unsigned char*)src;
	while (i < n)
	{
		dest[i] = sr[i];
		if (dest[i] == (unsigned char)c)
			return ((void*)(&dst[i + 1]));
		i++;
	}
	return (NULL);
}
