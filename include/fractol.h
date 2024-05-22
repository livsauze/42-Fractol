/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:31:10 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/22 15:32:58 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "events.h"
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>

# define MANDELBROT 1
# define JULIA 2

# define HEIGHT 1500
# define WIDTH 1550

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF00000
# define BLUE 0x0000FF
# define GREEN 0x00FF00

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels;
	int		bpp; //bytes per pixel
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_complex
{
	double	x; //Real nb
	double	y; //Imaginary nb
}			t_complex;

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	char	*name;
	int		set;
	t_img	img;
	double	escape_val;
	int		iter;
	double	julia_x;
	double	julia_y;
}			t_fractol;

/* **********************************ERRORS********************************** */
void	ft_handle_errors(int ac, char **av, t_fractol *f);
void	ft_msg(t_fractol *f);

/* ******************************INITIALISATION****************************** */
void	ft_init(t_fractol	*f);
void	ft_clean_init(t_fractol *f);
void	ft_data_init(t_fractol *f);
void	ft_get_fractal(char **av, int ac, t_fractol *f);

/* **********************************RENDER********************************** */
void	ft_render(t_fractol *f);
void	ft_handle_pixel(int x, int y, t_fractol *f);
void	ft_put_pixel(int x, int y, t_img *img, int color);

/* **********************************EVENTS********************************** */
int		ft_key_events(int keycode, t_fractol *mlx);

/* ***********************************EXIT*********************************** */
void	ft_exit(int code, t_fractol *f);
int		ft_clean_exit(t_fractol	*f);

/* **********************************UTILS*********************************** */
double	ft_map(double n, double n_min, double n_max, double o_min, double o_max);
t_complex	ft_sum(t_complex z1, t_complex z2);
t_complex	ft_square(t_complex z);

#endif