/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/22 18:54:03 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

uintmax_t	digit_counter_e_2(long double num, Formatter *fr)
{
	int					mass[16500];
	int					i;
	int					u;
	union long_double	f;

	f.f = num;
	put_zero_to_array(mass, &i);
	u = f.bin.exp - 16383 - 63;
	put_in_intmass(mass, f.bin.frac);
	put_multiply_2x5_array(mass, &u, &i);
	i = 16499;
	if (num > -1 && num < 1)
	{
		finder_not_zero(mass, &i);
		rounder_double(mass, fr->precision, i);
		finder_not_zero(mass, &i);
	}
	else
		while (mass[i] == 0 && i > (-1 * u))
			i--;
	if (u < 0)
		return (i - (-1 * u));
	return (i);
}

uintmax_t	returner_e_1(long double num, intmax_t i, int u)
{
	if (num == 0)
		return (0);
	if (num > -1 && num < 1)
		return ((-1 * u) - i);
	if (u < 0)
		return (i - (-1 * u));
	return (i);
}

uintmax_t	digit_counter_e_1(long double num, Formatter *fr)
{
	int					mass[16500];
	int					i;
	int					u;
	union long_double	f;

	f.f = num;
	i = 0;
	put_zero_to_array(mass, &i);
	u = f.bin.exp - 16383 - 63;
	put_in_intmass(mass, f.bin.frac);
	put_multiply_2x5_array(mass, &u, &i);
	i = 16499;
	if (num > -1 && num < 1)
	{
		finder_not_zero(mass, &i);
		rounder_double(mass, fr->precision, i);
		finder_not_zero(mass, &i);
	}
	else
		while (mass[i] == 0 && i > (-1 * u))
			i--;
	return (returner_e_1(num, i, u));
}

uintmax_t	digit_counter_e(long double num, Formatter *fr)
{
	int			i;
	int			u;

	u = 0;
	i = digit_counter_e_1((long double )num, fr);
	while (i / 10)
	{
		i = i / 10;
		u++;
	}
	u++;
	return (u);
}

uintmax_t	digit_counter_long_double(long double num,
			uintmax_t precision, Formatter *fr)
{
	int					mass[16500];
	int					i;
	int					u;
	union long_double	f;

	f.f = num;
	i = 0;
	put_zero_to_array(mass, &i);
	u = f.bin.exp - 16383 - 63;
	put_in_intmass(mass, f.bin.frac);
	put_multiply_2x5_array(mass, &u, &i);
	i = 16499;
	while (mass[i] == 0 && i > (-1 * u))
		i--;
	if (u < 0)
		return (i - ((-1) * u) + precision + 1);
	else if (fr->flags[3] == '#' && precision == 0)
		return (i + 2);
	else
		return (i + 1 + precision);
}

uintmax_t	digit_counter_double(double num1,
			uintmax_t precision, Formatter *fr)
{
	int					mass[16500];
	int					i;
	int					u;
	union long_double	f;
	long double			num;

	num = (long double)num1;
	f.f = num;
	i = 0;
	put_zero_to_array(mass, &i);
	u = f.bin.exp - 16383 - 63;
	put_in_intmass(mass, f.bin.frac);
	put_multiply_2x5_array(mass, &u, &i);
	i = 16499;
	while (mass[i] == 0 && i > (-1 * u))
		i--;
	if (u < 0)
		return (i - ((-1) * u) + precision + 1);
	else if (fr->flags[3] == '#' && precision == 0)
		return (i + 2);
	else
		return (i + 1 + precision);
}
