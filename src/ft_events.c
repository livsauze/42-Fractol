/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:56:04 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/28 15:55:13 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_switch_color(t_fractol *f)
{
	if (f->space == 0)
		f->color = WHITE;
	else if (f->space == 1)
		f->color = BLACK;
	else if (f->space == 2)
		f->color = CYAN;
	else if (f->space == 3)
		f->color = BLUE;
	else if (f->space == 4)
		f->color = NAVY;
	else if (f->space == 5)
		f->color = GREEN;
	else if (f->space == 6)
		f->color = YELLOW;
	else if (f->space == 7)
		f->color = ORANGE;
	else if (f->space == 8)
		f->color = RED;
	else if (f->space == 9)
		f->color = PINK;
	else if (f->space == 10)
	{
		f->color = PURPLE;
		f->space = -1;
	}
}

int	ft_key_events(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		ft_exit(EXIT_SUCCESS, f);
	else if (keycode == XK_Up || keycode == W)
		f->shift_y -= (0.5 * f->zoom);
	else if (keycode == XK_Down || keycode == A)
		f->shift_y += (0.5 * f->zoom);
	else if (keycode == XK_Left || keycode == S)
		f->shift_x += (0.5 * f->zoom);
	else if (keycode == XK_Right || keycode == D)
		f->shift_x -= (0.5 * f->zoom);
	else if (keycode == PLUS)
		f->iter += 10;
	else if (keycode == MINUS)
		f->iter -= 10;
	else if (keycode == SPACE)
	{
		f->space++;
		ft_switch_color(f);
	}
	ft_render(f);
	return (0);
}

int	ft_mouse_events(int keycode, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (keycode == ZOOM_IN)
		f->zoom *= 0.97;
	else if (keycode == ZOOM_OUT)
		f->zoom *= 1.03;
	ft_render(f);
	return (0);
}
