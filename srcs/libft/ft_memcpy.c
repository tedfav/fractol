/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:30:59 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/13 08:09:36 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sr;

	dest = (char*)dst;
	sr = (char*)src;
	while (n > 0)
	{
		*dest = *sr;
		dest++;
		sr++;
		n--;
	}
	return (dst);
}
