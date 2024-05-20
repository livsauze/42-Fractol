/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:31:10 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/20 17:02:26 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "events.h"
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>

# define MANDELBROT 1
# define JULIA 2

# define HEIGHT 1500
# define WIDTH 1550

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*name;
	int		set;
}			t_fractol;

/* **********************************ERRORS********************************** */
void	ft_handle_errors(int ac, char **av, t_fractol *f);
void	ft_msg(t_fractol *f);

/* ******************************INITIALISATION****************************** */
void	ft_init(t_fractol	*f);
void	ft_get_fractal(char **av, int ac, t_fractol *f);

/* **********************************EVENTS*********************************** */
int		ft_key_events(int keycode, t_fractol *mlx);

/* **********************************EXIT*********************************** */
void	ft_exit(int code, t_fractol *f);
int		ft_clean_exit(t_fractol	*f);

#endif