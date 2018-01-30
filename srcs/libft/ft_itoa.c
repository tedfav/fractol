/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:39:07 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/15 10:39:43 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_len(int n)
{
	int i;
	int nb;

	i = 0;
	nb = n;
	if (n < 0)
	{
		i++;
		nb = -n;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void		ft_res(char *res, int i, int abs, int n)
{
	while (i >= 0)
	{
		if (i == 0 && n < 0)
			res[i] = '-';
		else
		{
			res[i] = (abs % 10) + '0';
			abs = abs / 10;
		}
		i--;
	}
}

char			*ft_itoa(int n)
{
	char	*res;
	int		abs;
	int		i;

	i = ft_len(n);
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res[i] = '\0';
	i--;
	abs = n;
	if (n < 0)
		abs = -n;
	ft_res(res, i, abs, n);
	return (res);
}
