/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:07:28 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/21 16:18:10 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_exit(int code, t_fractol *f)
{
	if (!f)
		exit(code);
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx, f->img.img_ptr);
	if (f->window)
		mlx_destroy_window(f->mlx, f->window);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(code);
}

int	ft_clean_exit(t_fractol	*f)
{
	ft_exit(EXIT_SUCCESS, f);
	return (0);
}
