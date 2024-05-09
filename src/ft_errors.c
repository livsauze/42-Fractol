/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:08:21 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/09 18:25:48 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.c"

void	ft_handle_errors(int ac, char **av, t_fractol *f)
{
	if (ac < 2)
		ft_msg(&f);
}

void	ft_msg(t_fractol *f)
{
	ft_printf("You need to choose a fractal between :\n")
}
