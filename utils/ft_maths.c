/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:43:43 by livsauze          #+#    #+#             */
/*   Updated: 2024/05/27 16:26:17 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_map(double n, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * n / o_max + n_min);
}

t_complex	ft_sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	ft_square(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

int	ft_spaces_sign(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	return (i);
}

double	ft_atodbl(char *str)
{
	int		i;
	int		sign;
	double	res;
	double	div;

	i = ft_spaces_sign(str);
	res = 0;
	sign = 1;
	div = 0.1;
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		res = (res * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (res * sign);
}
