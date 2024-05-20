/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:00:06 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/20 17:03:30 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		ft_exit(EXIT_FAILURE, f);
}

void	ft_get_fractal(char **av, int ac, t_fractol *f)
{
	if (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1]) + 1) == 0)
		f->set = MANDELBROT;
	else if (ft_strncmp(av[1], "julia", ft_strlen(av[1]) + 1) == 0)
		f->set = JULIA;
	else if (f->set == JULIA && ac < 5)
	{
		ft_printf("Please enter starting values between -2.0 and 2.0\n");
		ft_printf("Try something like : ./fractol julia 0.8 0.01\n");
		ft_exit(EXIT_FAILURE, f);
	}
	else
	{
		ft_msg(f);
		ft_exit(EXIT_FAILURE, f);
	}
}
