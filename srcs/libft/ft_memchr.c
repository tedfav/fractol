/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:26:30 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/10 14:36:21 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sr;

	sr = (unsigned char*)s;
	while (n > 0)
	{
		if (*sr == (unsigned char)c)
			return (sr);
		sr++;
		n--;
	}
	return (NULL);
}
