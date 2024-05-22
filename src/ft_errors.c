/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:08:21 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/22 15:28:04 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_handle_errors(int ac, char **av, t_fractol *f)
{
	(void)av;
	if (ac < 2)
	{
		ft_msg(f);
		exit(EXIT_FAILURE);
	}
	ft_get_fractal(av, ac, f);
}

void	ft_msg(t_fractol *f)
{
	(void)f;
	ft_printf("You need to choose a fractal between :\n");
	ft_printf("-mandelbrot\n-julia\n");
}
void	ft_get_fractal(char **av, int ac, t_fractol *f)
{
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1]) + 1) == 0)
		f->set = MANDELBROT;
	else if (ft_strncmp(av[1], "julia", ft_strlen(av[1]) + 1) == 0)
		f->set = JULIA;
	else
	{
		ft_msg(f);
		ft_exit(EXIT_FAILURE, f);
	}
	if (f->set == JULIA && ac != 4)
	{
		ft_printf("Please enter starting values between -2.0 and 2.0\n");
		ft_printf("Try something like : ./fractol julia 0.285 0.013\n");
		ft_exit(EXIT_FAILURE, f);
	}
}