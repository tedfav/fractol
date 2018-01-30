/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:36:37 by tfavart           #+#    #+#             */
/*   Updated: 2018/01/16 15:08:12 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_up_and_down(int key, t_mlx *smlx)
{
	if (key == 125)
	{
		smlx->coord.posy += 50;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &(smlx->img));
	}
	if (key == 126)
	{
		smlx->coord.posy -= 50;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &(smlx->img));
	}
}

static void		ft_right_and_left(int key, t_mlx *smlx)
{
	if (key == 124)
	{
		smlx->coord.posx += 50;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &(smlx->img));
	}
	if (key == 123)
	{
		smlx->coord.posx -= 50;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &(smlx->img));
	}
}

static void		ft_zoom(int key, t_mlx *smlx)
{
	if (key == 78)
	{
		smlx->coord.spanx /= 1.3;
		smlx->coord.spany /= 1.3;
		smlx->coord.zoomx = smlx->wlenx / 2 / smlx->coord.spanx;
		smlx->coord.zoomy = smlx->wleny / 2 / smlx->coord.spany;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &(smlx->img));
	}
	if (key == 69)
	{
		smlx->coord.spanx *= 1.3;
		smlx->coord.spany *= 1.3;
		smlx->coord.zoomx = smlx->wlenx / 2 / smlx->coord.spanx;
		smlx->coord.zoomy = smlx->wleny / 2 / smlx->coord.spany;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &(smlx->img));
	}
}

static void		ft_psy(int key, t_mlx *smlx)
{
	if (key == 83 && smlx->mouse_move == 0)
		smlx->mouse_move = 1;
	else if (key == 83 && smlx->mouse_move == 1)
		smlx->mouse_move = 0;
	if (key == 1)
	{
		smlx->color++;
		if (smlx->color > 2)
			smlx->color = 0;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &(smlx->img));
	}
	if (key == 49)
	{
		ft_init(smlx);
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &(smlx->img));
	}
}

int				ft_key_hook(int keycode, t_mlx *smlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		exit(0);
	}
	if (keycode == 67 && smlx->coord.iter * 2 < 10000)
	{
		smlx->coord.iter *= 2;
		mlx_clear_window(smlx->mlx, smlx->win);
		mlx_destroy_image(smlx->mlx, smlx->img.ptr);
		ft_image(smlx, &(smlx->img));
	}
	ft_right_and_left(keycode, smlx);
	ft_up_and_down(keycode, smlx);
	ft_zoom(keycode, smlx);
	ft_psy(keycode, smlx);
	return (0);
}
