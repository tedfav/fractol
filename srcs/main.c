/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 08:02:31 by tfavart           #+#    #+#             */
/*   Updated: 2018/01/22 13:31:51 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init(t_mlx *smlx)
{
	if (smlx->i == 1)
	{
		smlx->coord.spanx = (0.6 - -2.1) / 2;
		smlx->coord.spany = (1.2 - -1.2) / 2;
		smlx->coord.cenx = (0.6 + -2.1) / 2;
		smlx->coord.ceny = (1.2 + -1.2) / 2;
		smlx->coord.cr = 0;
		smlx->coord.ci = 0;
	}
	if (smlx->i == 3 || smlx->i == 2)
	{
		smlx->coord.spanx = (1.2 - -1.2);
		smlx->coord.spany = (1.2 - -1.2);
		smlx->coord.cenx = (1.2 + -1.2) / 2;
		smlx->coord.ceny = (1.2 + -1.2) / 2;
		smlx->coord.cr = 0;
		smlx->coord.ci = 0;
	}
	smlx->mouse_move = 0;
	smlx->coord.iter = 100;
	smlx->coord.posx = 0;
	smlx->coord.posy = 0;
	smlx->coord.zoomx = smlx->wlenx / 2 / smlx->coord.spanx;
	smlx->coord.zoomy = smlx->wleny / 2 / smlx->coord.spany;
	smlx->color = 0;
}

static int		ft_window(char *av, void *imlx)
{
	t_mlx		smlx;
	char		*title;

	title = ft_strjoin("Fractol ", av);
	smlx.mlx = imlx;
	smlx.wlenx = 800;
	smlx.wleny = 800;
	smlx.i = ft_atoi(av);
	if (smlx.i < 1 || smlx.i > 3)
		return (0);
	ft_init(&smlx);
	smlx.win = mlx_new_window(smlx.mlx, smlx.wlenx, smlx.wleny, title);
	free(title);
	ft_image(&smlx, &(smlx.img));
	mlx_hook(smlx.win, 6, 1L < 6, &ft_mouse_move, &smlx);
	mlx_key_hook(smlx.win, &ft_key_hook, &smlx);
	mlx_mouse_hook(smlx.win, &ft_mouse, &smlx);
	mlx_loop(smlx.mlx);
	return (0);
}

static void		ft_menu(void)
{
	ft_putstr("listes des commandes :\n\n");
	ft_putstr("deplacement : fleches directionnelles\n");
	ft_putstr("zoom sourie : molette\n");
	ft_putstr("zoom clavier : + - pave numeriaue\n");
	ft_putstr("couleur suivante : s\n");
	ft_putstr("reset : espace\n");
	ft_putstr("variation julia : 1 pave numerique\n");
	ft_putstr("augmenter les detailles : * pave numerique\n");
}

int				main(int ac, char **av)
{
	void		*imlx;

	if (ac != 2 || (ft_strcmp(av[1], "1") != 0 && ft_strcmp(av[1], "2") != 0
				&& ft_strcmp(av[1], "3") != 0))
	{
		ft_putstr("Usage: ./fractol 1 or 2 or 3\n");
		return (0);
	}
	ft_menu();
	imlx = mlx_init();
	ft_window(av[1], imlx);
	return (0);
}
