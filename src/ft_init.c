/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:00:06 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/28 15:47:22 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->window = NULL;
	f->img.img_ptr = NULL;
	f->name = NULL;
	f->set = 0;
	f->escape_val = 4;
	f->iter = 42;
	f->color = WHITE;
	f->space = 0;
	f->julia_x = 0.0;
	f->julia_y = 0.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
}

void	ft_init_events(t_fractol *f)
{
	mlx_hook(f->window, 2, 1, ft_key_events, f);
	mlx_mouse_hook(f->window, ft_mouse_events, f);
	mlx_hook(f->window, 17, 0, ft_clean_exit, f);
}

void	ft_init(t_fractol *f)
{
	if (f->set == 1)
		f->name = "MANDELBROT";
	else if (f->set == 2)
		f->name = "JULIA";
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_printf("Error connecting to mlx");
		exit(EXIT_FAILURE);
	}
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	if (!f->window)
		ft_exit(EXIT_FAILURE, f);
	f->img.img_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
		ft_exit(EXIT_FAILURE, f);
	f->img.pixels = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bpp, &f->img.line_len, &f->img.endian);
	ft_init_events(f);
}
