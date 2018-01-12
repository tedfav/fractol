/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 07:18:15 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/15 13:18:02 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len)
{
	size_t		i;
	size_t		j;
	char		*str1;
	char		*str2;

	i = 0;
	str1 = (char*)haystack;
	str2 = (char*)needle;
	if (str2[0] == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while ((str1[i + j] == str2[j] || str2[j] == '\0') && ((i + j) <= len))
		{
			if (str2[j] == '\0')
				return (&str1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
