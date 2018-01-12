/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:43:34 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/16 10:59:29 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sr;
	size_t			i;

	i = 0;
	dest = (unsigned char*)(dst);
	sr = (unsigned char*)(src);
	if (dest == sr)
		return (dest);
	if (src < dst)
	{
		dest = (unsigned char*)(&dst[len - 1]);
		sr = (unsigned char*)(&src[len - 1]);
		while (len > 0)
		{
			*dest = *sr;
			len--;
			dest--;
			sr--;
		}
	}
	else
		dest = ft_memcpy(dst, src, len);
	return ((void*)dst);
}
