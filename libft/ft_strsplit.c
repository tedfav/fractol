/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:44:25 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/15 19:49:20 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_len_w(const char *str, char c)
{
	int			len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
	{
		len++;
	}
	return (len);
}

static int		ft_len_tab(const char *str, char c)
{
	int			len;
	int			i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 && str[i] != c) || (str[i] != c && str[i - 1] == c))
			len++;
		i++;
	}
	return (len);
}

static void		*ft_free_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	char		*w;
	int			i;
	int			y;
	int			len;

	i = 0;
	len = (s) ? ft_len_tab(s, c) : 0;
	if (!(tab = (char**)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		y = 0;
		while (*s && *s == c)
			s++;
		if (!(w = (char*)malloc(sizeof(char) * (ft_len_w(s, c) + 1))))
			return (ft_free_tab(tab));
		while (*s && *s != c)
			w[y++] = *(s++);
		w[y] = '\0';
		tab[i++] = w;
	}
	tab[i] = 0;
	return (tab);
}
