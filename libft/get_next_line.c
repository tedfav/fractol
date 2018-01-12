/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 08:00:00 by tfavart           #+#    #+#             */
/*   Updated: 2017/12/07 13:23:38 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_realloc(char *str, int red)
{
	char			*tmp;

	if (str == NULL || *str == '\0')
	{
		free(str);
		if (!(str = ft_strnew(red)))
			return (0);
	}
	else
	{
		tmp = str;
		if (!(str = ft_strnew(ft_strlen(tmp) + red)))
			return (0);
		str = ft_memcpy(str, tmp, ft_strlen(tmp));
		free(tmp);
	}
	return (str);
}

static int			ft_line(char **line, char **str)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = *str;
	if (*tmp == '\0')
		return (1);
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	if (!(*line = ft_strnew(i)))
		return (-1);
	*line = ft_memcpy(*line, *str, i);
	if ((*str)[i] == '\n')
		i++;
	*str = ft_strsub(*str, i, ft_strlen(*str) - i);
	free(tmp);
	return (0);
}

static int			ft_read(int fd, char **str)
{
	char			*buff;
	int				red;

	red = 1;
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!(ft_strchr(buff, '\n')) && red != 0)
	{
		if ((red = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		if (!(*str = ft_realloc(*str, red)))
			return (-1);
		ft_strncat(*str, buff, red);
	}
	free(buff);
	return (red);
}

int					get_next_line(int fd, char **line)
{
	static char		*str;
	int				red;
	int				i;

	i = 0;
	if (!(line))
		return (-1);
	if ((red = ft_read(fd, &str)) == -1)
		return (-1);
	if ((i = ft_line(line, &str)) == -1)
		return (-1);
	if (str == NULL && red == 0)
		return (0);
	if (*str == '\0' && red == 0 && i == 1)
		return (0);
	return (1);
}
