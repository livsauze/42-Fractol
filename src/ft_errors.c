/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:08:21 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/27 16:23:23 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_handle_errors(int ac, char **av, t_fractol *f)
{
	if (ac < 2)
	{
		ft_msg(f);
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1]) + 1) == 0)
		f->set = MANDELBROT;
	else if (ft_strncmp(av[1], "julia", ft_strlen(av[1]) + 1) == 0)
	{
		f->set = JULIA;
		ft_julia(av, ac, f);
	}
	else
		ft_msg(f);
}

void	ft_msg(t_fractol *f)
{
	ft_printf("You need to choose a fractal between :\n");
	ft_printf("-mandelbrot\n-julia\n");
	ft_exit(EXIT_FAILURE, f);
}

void	ft_msg_julia(t_fractol *f)
{
	ft_printf("Please enter starting values between -2.0 and 2.0\n");
	ft_printf("Try something like : ./fractol julia 0.285 0.013\n");
	ft_exit(EXIT_FAILURE, f);
}

int	ft_check_values(double nb1, double nb2)
{
	if ((nb1 < -2.0 || nb1 > 2.0) || (nb2 < -2.0 || nb2 > 2.0))
		return (1);
	return (0);
}

void	ft_julia(char **av, int ac, t_fractol *f)
{
	if (f->set == JULIA && ac != 4)
		ft_msg_julia(f);
	else if (f->set == JULIA && ac == 4)
	{
		if (ft_check_values(ft_atodbl(av[2]), ft_atodbl(av[3])) == 1)
			ft_msg_julia(f);
		else
		{
			f->julia_x = ft_atodbl(av[2]);
			f->julia_y = ft_atodbl(av[3]);
		}
	}
}
