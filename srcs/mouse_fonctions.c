/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:08:35 by tfavart           #+#    #+#             */
/*   Updated: 2018/01/12 15:24:56 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init(t_mlx *smlx)
{
	if (smlx->i == 1)
	{
		smlx->coord.cr = 0;
		smlx->coord.ci = 0;
	}
	if (smlx->i == 3 || smlx->i == 2)
	{
		smlx->coord.cr = 0;
		smlx->coord.ci = 0;
	}
}

int				ft_mouse_move(int x, int y, t_mlx *smlx)
{
	static int	xr = 0;

	if (smlx->mouse_move == 1)
	{
		y = 0;
		if (x > xr)
			smlx->coord.cr += 0.001;
		if (x < xr)
			smlx->coord.cr -= 0.001;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &smlx->img);
	}
	else
	{
		ft_init(smlx);
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &smlx->img);
	}
	xr = x;
	return (0);
}

int				ft_mouse(int mousecode, int x, int y, t_mlx *smlx)
{
	if (mousecode == 1)
	{
		smlx->coord.cenx = smlx->coord.cenx + (x - smlx->wlenx / 2) * 2 *
			(smlx->coord.spanx / smlx->wlenx);
		smlx->coord.ceny = smlx->coord.ceny + (y - smlx->wleny / 2) * 2 *
			(smlx->coord.spany / smlx->wleny);
		smlx->coord.spanx /= 2;
		smlx->coord.spany /= 2;
		smlx->coord.zoomx = smlx->wlenx / 2 / smlx->coord.spanx;
		smlx->coord.zoomy = smlx->wleny / 2 / smlx->coord.spany;
		smlx->coord.cenx = smlx->coord.cenx - (x - smlx->wlenx / 2) * 2 *
			(smlx->coord.spanx / smlx->wlenx);
		smlx->coord.ceny = smlx->coord.ceny - (y - smlx->wleny / 2) * 2 *
			(smlx->coord.spany / smlx->wleny);
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &smlx->img);
	}
	return (0);
}
