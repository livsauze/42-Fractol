/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:08:21 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/20 15:16:44 by livsauze         ###   ########.fr       */
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
