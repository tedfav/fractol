/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:42:13 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/15 15:40:33 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_printable(char *str)
{
	int		count;

	count = 0;
	if (str[count] == '\0')
		return (1);
	while ((str[count] > 31 && str[count] < 127) || str[count] == '\0')
	{
		if (str[count] == '\0')
			return (1);
		count++;
	}
	return (0);
}
