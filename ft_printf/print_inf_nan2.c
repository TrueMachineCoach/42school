/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inf_nan2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:28:03 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:50:57 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		print_inf_nan_1(int *x)
{
	if ((*x) == 1)
		write(1, "inf", 3);
	else if ((*x) == -1)
		write(1, "-inf", 4);
	else
		write(1, "nan", 3);
	if ((*x) == -1)
		return (4);
	else
		return (3);
}

int		print_inf_nan_2(int *i, size_t *j)
{
	while ((size_t)(*i) > (*j))
	{
		write(1, " ", 1);
		(*i)--;
	}
	return (*j - *i);
}

int		inf_nan_detector_long_double(long double num)
{
	union long_double ld;

	ld.f = num;
	if (ld.bin.frac << 1 == 0 && ld.bin.exp == 32767)
	{
		if (ld.bin.sign == 0)
			return (1);
		else
			return (-1);
	}
	if (ld.bin.frac != 0 && ld.bin.exp == 32767)
		return (2);
	return (0);
}

int		inf_nan_detector_double(double num)
{
	union double_double d;

	d.f = num;
	if (d.bin.frac == 0 && d.bin.exp == 2047)
	{
		if (d.bin.sign == 0)
			return (1);
		else
			return (-1);
	}
	if (d.bin.frac != 0 && d.bin.exp == 2047)
		return (2);
	return (0);
}
