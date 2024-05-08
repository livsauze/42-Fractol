/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:30:51 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/08 16:31:37 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main()
{
	void	*mlx_connection;
	void	*window;

	mlx_connection = mlx_init();
	window = mlx_new_window(mlx_connection, 4000, 4000, "Window");
	mlx_loop(mlx_connection);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
}