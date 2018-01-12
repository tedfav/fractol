/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:39:58 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/15 10:40:57 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_alpha(char *str)
{
	int	count;

	count = 0;
	if (str[0] == '\0')
		return (1);
	while ((str[count] >= 'A' && str[count] <= 'Z') ||
			(str[count] >= 'a' && str[count] <= 'z') ||
			str[count] == '\0')
	{
		if (str[count] == '\0')
			return (1);
		count++;
	}
	return (0);
}
