/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 07:59:00 by tfavart           #+#    #+#             */
/*   Updated: 2018/01/16 15:08:31 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_smlxcp(t_mlx *org, t_mlx *dst, int t)
{
	dst->mlx = org->mlx;
	dst->win = org->win;
	dst->wlenx = org->wlenx;
	dst->wleny = org->wleny;
	dst->i = org->i;
	dst->mouse_move = org->mouse_move;
	dst->coord.spanx = org->coord.spanx;
	dst->coord.spany = org->coord.spany;
	dst->coord.cenx = org->coord.cenx;
	dst->coord.ceny = org->coord.ceny;
	dst->coord.cr = org->coord.cr;
	dst->coord.ci = org->coord.ci;
	dst->coord.zoomx = org->coord.zoomx;
	dst->coord.zoomy = org->coord.zoomy;
	dst->coord.iter = org->coord.iter;
	dst->coord.posx = org->coord.posx;
	dst->coord.posy = org->coord.posy;
	dst->img.ptr = org->img.ptr;
	dst->img.str = org->img.str;
	dst->img.size_l = org->img.size_l;
	dst->t = t;
	dst->color = org->color;
}

void				ft_pixel(t_mlx *smlx, int x, int y, unsigned long long iter)
{
	int				color;
	int				i;
	char			*str;

	str = smlx->img.str;
	i = x * 4 + y * smlx->img.size_l;
	if (smlx->color == 0)
		color = 0xFF0000 * iter / 255;
	else if (smlx->color == 1)
		color = 0xFFFFFF * iter / smlx->coord.iter;
	else if (smlx->color == 2)
		color = 0x00FF00 * iter / smlx->coord.iter;
	else
		color = 0xFFFFFF;
	str[i] = color;
	str[i + 1] = color >> 8;
	str[i + 2] = color >> 16;
}

static void			*ft_coord(void *mlx)
{
	int				x;
	int				y;
	t_mlx			*smlx;

	smlx = mlx;
	y = smlx->t;
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
	return (NULL);
}

void				ft_thread(t_mlx *smlx)
{
	pthread_t		thread[800];
	t_mlx			tab[800];
	int				t;

	t = 0;
	while (t < 800)
	{
		ft_smlxcp(smlx, &(tab[t]), t);
		pthread_create(&(thread[t]), NULL, &ft_coord, (void*)&(tab[t]));
		t++;
	}
	t = 0;
	while (t < 800)
	{
		pthread_join(thread[t], NULL);
		t++;
	}
}

int					ft_image(t_mlx *smlx, t_img *img)
{
	img->ptr = mlx_new_image(smlx->mlx, smlx->wlenx, smlx->wleny);
	img->str = mlx_get_data_addr(img->ptr, &(img->bbp),
			&(img->size_l), &(img->endian));
	ft_thread(smlx);
	mlx_put_image_to_window(smlx->mlx, smlx->win, img->ptr, 0, 0);
	return (0);
}
