/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:30:51 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/27 16:23:08 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	ft_clean_init(&f);
	ft_handle_errors(ac, av, &f);
	ft_init(&f);
	ft_render(&f);
	mlx_loop(f.mlx);
	free(f.mlx);
	return (0);
}
