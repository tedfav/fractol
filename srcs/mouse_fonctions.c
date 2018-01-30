/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:08:35 by tfavart           #+#    #+#             */
/*   Updated: 2018/01/16 11:29:21 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_mouse_move(int x, int y, t_mlx *smlx)
{
	static int	xr = 0;

	if (smlx->mouse_move == 1)
	{
		y = 0;
		if (x > xr)
			smlx->coord.cr += 0.0001;
		if (x < xr)
			smlx->coord.cr -= 0.0001;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &smlx->img);
		xr = x;
	}
	return (0);
}

static void		ft_zoom_up(int x, int y, t_mlx *smlx)
{
	smlx->coord.cenx = smlx->coord.cenx + (x + smlx->coord.posx
			- smlx->wlenx / 2) * 2 * (smlx->coord.spanx / smlx->wlenx);
	smlx->coord.ceny = smlx->coord.ceny + (y + smlx->coord.posy
			- smlx->wleny / 2) * 2 * (smlx->coord.spany / smlx->wleny);
	smlx->coord.spanx /= 1.3;
	smlx->coord.spany /= 1.3;
	smlx->coord.zoomx = smlx->wlenx / 2 / smlx->coord.spanx;
	smlx->coord.zoomy = smlx->wleny / 2 / smlx->coord.spany;
	smlx->coord.cenx = smlx->coord.cenx - (x + smlx->coord.posx
			- smlx->wlenx / 2) * 2 * (smlx->coord.spanx / smlx->wlenx);
	smlx->coord.ceny = smlx->coord.ceny - (y + smlx->coord.posy
			- smlx->wleny / 2) * 2 * (smlx->coord.spany / smlx->wleny);
	mlx_clear_window(smlx->mlx, smlx->win);
	mlx_destroy_image(smlx->mlx, smlx->img.ptr);
	ft_image(smlx, &smlx->img);
}

static void		ft_zoom_down(int x, int y, t_mlx *smlx)
{
	smlx->coord.cenx = smlx->coord.cenx + (x + smlx->coord.posx
			- smlx->wlenx / 2) * 2 * (smlx->coord.spanx / smlx->wlenx);
	smlx->coord.ceny = smlx->coord.ceny + (y + smlx->coord.posy
			- smlx->wleny / 2) * 2 * (smlx->coord.spany / smlx->wleny);
	smlx->coord.spanx *= 1.3;
	smlx->coord.spany *= 1.3;
	smlx->coord.zoomx = smlx->wlenx / 2 / smlx->coord.spanx;
	smlx->coord.zoomy = smlx->wleny / 2 / smlx->coord.spany;
	smlx->coord.cenx = smlx->coord.cenx - (x + smlx->coord.posx
			- smlx->wlenx / 2) * 2 * (smlx->coord.spanx / smlx->wlenx);
	smlx->coord.ceny = smlx->coord.ceny - (y + smlx->coord.posy
			- smlx->wleny / 2) * 2 * (smlx->coord.spany / smlx->wleny);
	mlx_clear_window(smlx->mlx, smlx->win);
	mlx_destroy_image(smlx->mlx, smlx->img.ptr);
	ft_image(smlx, &smlx->img);
}

int				ft_mouse(int mousecode, int x, int y, t_mlx *smlx)
{
	if (mousecode == 5)
		ft_zoom_up(x, y, smlx);
	if (mousecode == 4)
		ft_zoom_down(x, y, smlx);
	return (0);
}
