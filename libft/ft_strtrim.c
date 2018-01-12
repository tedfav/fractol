/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:46:38 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/15 18:44:20 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_trim(char s)
{
	if (s == '\n' || s == '\t' || s == ' ')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	int		len;

	if (s == NULL)
		return (NULL);
	tmp = (char*)s;
	while (ft_trim(*tmp) == 1 && *tmp != '\0')
		tmp++;
	if (ft_strcmp(tmp, "") == 0)
		return (ft_strdup(""));
	len = ft_strlen(tmp);
	while (ft_trim(tmp[len - 1]) == 1)
		len--;
	return (ft_strsub(tmp, 0, len));
}
