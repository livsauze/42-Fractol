/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:31:10 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/28 16:25:34 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "events.h"
# include "colors.h"
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>

# define MANDELBROT 1
# define JULIA 2

# define HEIGHT 1500
# define WIDTH 1500

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_fractol
{
	t_img	img;
	void	*mlx;
	void	*window;
	char	*name;
	int		set;
	int		iter;
	int		color;
	int		space;
	double	escape_val;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	zoom;
}			t_fractol;

/* **********************************ERRORS********************************** */
void		ft_handle_errors(int ac, char **av, t_fractol *f);
void		ft_msg(t_fractol *f);
void		ft_msg_julia(t_fractol *f);
void		ft_julia(char **av, int ac, t_fractol *f);
int			ft_check_values(double nb1, double nb2);

/* ******************************INITIALISATION****************************** */
void		ft_init(t_fractol	*f);
void		ft_clean_init(t_fractol *f);
void		ft_init_events(t_fractol *f);

/* **********************************RENDER********************************** */
void		ft_render(t_fractol *f);
void		ft_handle_pixel(int x, int y, t_fractol *f);
void		ft_put_pixel(int x, int y, t_img *img, int color);

/* **********************************EVENTS********************************** */
int			ft_key_events(int keycode, t_fractol *mlx);
int			ft_mouse_events(int keycode, int x, int y, t_fractol *f);

/* ***********************************EXIT*********************************** */
void		ft_exit(int code, t_fractol *f);
int			ft_clean_exit(t_fractol	*f);

/* **********************************UTILS*********************************** */
double		ft_map(double n, double n_min, double n_max, double o_max);
double		ft_atodbl(char *str);
t_complex	ft_sum(t_complex z1, t_complex z2);
t_complex	ft_square(t_complex z);

#endif
