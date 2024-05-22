/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:00:06 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/22 15:32:45 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->window = NULL;
	f->img.img_ptr = NULL;
	f->name = NULL;
}

void	ft_data_init(t_fractol *f)
{
	if (f->set == 1)
	{
		f->escape_val = 4;
		f->iter = 42;
	}
	// else if (f->set == 2)
	// {
		
	// }
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
	f->window = mlx_new_window(f->mlx,WIDTH, HEIGHT, f->name);
	if (!f->window)
		ft_exit(EXIT_FAILURE, f);
	f->img.img_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
		ft_exit(EXIT_FAILURE, f);
	f->img.pixels = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp, &f->img.line_len, &f->img.endian);
	ft_data_init(f);
}

