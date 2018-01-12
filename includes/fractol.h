/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 07:54:26 by tfavart           #+#    #+#             */
/*   Updated: 2018/01/12 15:11:38 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "../libft/libft.h"

typedef struct	s_img
{
	void		*ptr;
	char		*str;
	int			bbp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_coord
{
	double		spanx;
	double		spany;
	double		cenx;
	double		ceny;
	double		cr;
	double		ci;
	double		zoomx;
	double		zoomy;
	int			iter;
	int			posx;
	int			posy;
}				t_coord;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			wlenx;
	int			wleny;
	int			i;
	int			mouse_move;
	t_coord		coord;
	t_img		img;
}				t_mlx;

int				ft_key_hook(int keycode, t_mlx *smlx);
int				ft_image(t_mlx *smlx, t_img *img);
int				ft_mouse_move(int x, int y, t_mlx *smlx);
int				ft_mouse(int mousecode, int x, int y, t_mlx *smlx);
void			ft_coord(t_mlx *smlx);
void			ft_mandelbrot(t_coord *c, t_mlx *smlx, int x, int y);
void			ft_mandelbrot_3(t_coord *c, t_mlx *smlx, int x, int y);
void			ft_julia(t_coord *c, t_mlx *smlx, int x, int y);
void			ft_pixel(t_mlx *smlx, int x, int y, int iter);

#endif
