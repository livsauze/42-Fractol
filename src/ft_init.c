/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:00:06 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/09 19:21:05 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_printf("Error connecting to mlx");
		ft_exit(EXIT_FAILURE);
	}
	f->window = mlx_new_window(f->mlx, 900, 900, "FRACTOL");
}

void	ft_get_fractal(char **av, t_fractol *f)
{
	if (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1] + 1)) == 0)
		f->set = MANDELBROT;
	else if (ft_strncmp(av[1], "julia", ft_strlen(av[1] + 1)) == 0)
		f->set = JULIA;
	if (f->set == JULIA && ac < 5)
	{
		ft_printf("Please enter starting values between -2.0 and 2.0\n");
		ft_printf("Try something like : ./fractol julia 0.8 0.01\n")
		ft_exit(EXIT_FAILURE);
	}
}