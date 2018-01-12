/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 07:59:00 by tfavart           #+#    #+#             */
/*   Updated: 2018/01/10 12:08:19 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_pixel(t_mlx *smlx, int x, int y, int iter)
{
	int			color;
	int			i;
	char		*str;

	str = smlx->img.str;
	color = 0xFFFFFF * iter / 50;
	i = x * 4 + y * smlx->img.size_l;
	str[i] = color;
	str[i + 1] = color >> 8;
	str[i + 2] = color >> 16;
	str[i + 3] = color >> 24;
}

void			ft_coord(t_mlx *smlx)
{
	int			x;
	int			y;

	y = 0;
	while (y < smlx->wleny)
	{
		x = 0;
		while (x < smlx->wlenx)
		{
			if (smlx->i == 1)
				ft_mandelbrot(&(smlx->coord), smlx, x, y);
			if (smlx->i == 2)
				ft_mandelbrot_3(&(smlx->coord), smlx, x, y);
			if (smlx->i == 3)
				ft_julia(&(smlx->coord), smlx, x, y);
			x += 1;
		}
		y += 1;
	}
}

int				ft_image(t_mlx *smlx, t_img *img)
{
	img->ptr = mlx_new_image(smlx->mlx, smlx->wlenx, smlx->wleny);
	img->str = mlx_get_data_addr(img->ptr, &(img->bbp),
			&(img->size_l), &(img->endian));
	ft_coord(smlx);
	mlx_put_image_to_window(smlx->mlx, smlx->win, img->ptr, 0, 0);
	return (0);
}
