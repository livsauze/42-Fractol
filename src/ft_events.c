/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:56:04 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/20 15:48:51 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_key_events(int keycode, t_fractol *f)
{
	printf("keycode : %d\n", keycode);
	if (keycode == ESC)
		ft_exit(EXIT_SUCCESS, f);
	return (0);
}
