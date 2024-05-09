/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:30:51 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/09 18:35:05 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;
	
	ft_handle_errors(ac, av, &f);
	ft_get_fractal(av, &f);
	ft_init(&f);
	mlx_connection = mlx_init();
	window = mlx_new_window(mlx_connection, 400, 400, "Window");
	mlx_loop(mlx_connection);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
}