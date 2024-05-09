/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:31:10 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/09 18:41:54 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <libft.h>
# include <stdlib.h>

# define MANDELBROT 1
# define JULIA 2

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	void	*img;
	int		set;
}			t_fractol;

/***************************ERRORS*******************************/
void	ft_handle_errors(int ac, char **av, t_fractol *f);
void	ft_msg(t_fractol *f);
/************************INITIALISATION**************************/
void	ft_init(t_fractol	*f);

#endif