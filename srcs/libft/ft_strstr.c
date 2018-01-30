/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:09:25 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/13 06:13:42 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char*)haystack;
	str2 = (char*)needle;
	if (str2[0] == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str1[i + j] == str2[j] || str2[j] == '\0')
		{
			if (str2[j] == '\0')
				return (&str1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
