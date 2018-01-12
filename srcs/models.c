/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:36:50 by tfavart           #+#    #+#             */
/*   Updated: 2018/01/12 14:15:56 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_mandelbrot(t_coord *c, t_mlx *smlx, int x, int y)
{
	int			i;
	double		tmp;
	double		zr;
	double		zi;

	i = 0;
	zr = 0;
	zi = 0;
	c->cr = (x + c->posx) / c->zoomx + c->cenx - c->spanx;
	c->ci = (y + c->posy) / c->zoomy + c->ceny - c->spany;
	while (i < c->iter && (zr * zr + zi * zi) < 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + c->cr;
		zi = 2 * tmp * zi + c->ci;
		i += 1;
	}
	if ((zr * zr + zi * zi) >= 4 && i >= 10)
		ft_pixel(smlx, x, y, i);
}

void			ft_mandelbrot_3(t_coord *c, t_mlx *smlx, int x, int y)
{
	int			i;
	double		tmp;
	double		zr;
	double		zi;

	i = 0;
	zr = 0;
	zi = 0;
	c->cr = (x + c->posx) / c->zoomx + c->cenx - c->spanx;
	c->ci = (y + c->posy) / c->zoomy + c->ceny - c->spany;
	while (i < c->iter && (zr * zr + zi * zi) < 4)
	{
		tmp = zr;
		zr = zr * zr * zr * zr + zi * zi * zi * zi - 6 * zr * zr *
			zi * zi + c->cr;
		zi = 4 * tmp * tmp * tmp * zi - 4 * tmp * zi * zi * zi + c->ci;
		i += 1;
	}
	if ((zr * zr * zr - zi * zi) >= 4 && i >= 8)
		ft_pixel(smlx, x, y, i);
}

void			ft_julia(t_coord *c, t_mlx *smlx, int x, int y)
{
	int			i;
	double		tmp;
	double		zr;
	double		zi;
	double		cr;

	i = 0;
	cr = 0.285 + c->cr;
	c->ci = 0.01;
	zr = (x + c->posx) / c->zoomx + c->cenx - c->spanx;
	zi = (y + c->posy) / c->zoomy + c->ceny - c->spany;
	while (i < c->iter && (zr * zr + zi * zi) < 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * tmp * zi + c->ci;
		i += 1;
	}
	if ((zr * zr + zi * zi) >= 4 && i >= 30)
		ft_pixel(smlx, x, y, i);
}
