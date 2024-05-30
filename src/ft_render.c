/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:40:13 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/28 15:29:19 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_set_fractal(t_complex *z, t_complex *c, t_fractol *f)
{
	if (f->set == JULIA)
	{
		c->x = f->julia_x;
		c->y = f->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

// find the right pixel to color
void	ft_put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels + offset) = color;
}

void	ft_handle_pixel(int x, int y, t_fractol *f)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color_b;

	i = 0;
	z.x = (ft_map(x, -2, 2, WIDTH) * f->zoom) + f->shift_x;
	z.y = (ft_map(y, 2, -2, HEIGHT) * f->zoom) + f->shift_y;
	ft_set_fractal(&z, &c, f);
	while (i < f->iter)
	{
		z = ft_sum(ft_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_val)
		{
			color_b = ft_map(i, BLACK, WHITE, f->iter);
			ft_put_pixel(x, y, &f->img, color_b);
			return ;
		}
		i++;
	}
	ft_put_pixel(x, y, &f->img, f->color);
}

void	ft_render(t_fractol *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_handle_pixel(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img.img_ptr, 0, 0);
}
