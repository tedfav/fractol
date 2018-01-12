/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:05:47 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/10 08:00:01 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long	i;
	char			*tmp;

	i = 0;
	tmp = (char*)dst;
	while (src[i] && (i < len))
	{
		tmp[i] = src[i];
		i++;
	}
	while (i < len)
	{
		tmp[i] = '\0';
		i++;
	}
	return (dst);
}
