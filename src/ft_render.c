/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:40:13 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/21 16:20:12 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	//find the right pixel to color
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels + offset) = color;
}

void	ft_handle_pixel(int x, int y, t_fractol *f)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = ft_map(x, -2, 2, 0, WIDTH);
	c.y = ft_map(y, 2, -2, 0, HEIGHT);
	while (i < f->iter)
	{
		z = ft_sum(ft_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_val)
		{
			color = ft_map(i, BLACK, WHITE, 0, f->iter);
			ft_put_pixel(x, y, &f->img, color);
			return ;
		}
		++i;
	}
		ft_put_pixel(x, y, &f->img, WHITE);
}

void	ft_render(t_fractol *f)
{
	int	x;
	int	y;
	
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_handle_pixel(x, y, f);
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img.img_ptr, 0, 0);
}
