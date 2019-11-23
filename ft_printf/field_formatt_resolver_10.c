/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_10.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 14:07:22 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int		precision_recalculate_help_1(union long_double *f,
		int *mass, long double num)
{
	int i;
	int u;

	f->f = num;
	u = f->bin.exp - 16383 - 63;
	put_in_intmass(mass, f->bin.frac);
	i = 0;
	if (u >= 0)
		while (i < u)
		{
			intmass_multiply(mass, 2);
			i++;
		}
	else
		while (i < (-1 * u))
		{
			intmass_multiply(mass, 5);
			i++;
		}
	return (u);
}

int		precision_recalculate_help_2(uintmax_t precision, int u, int *mass)
{
	int reculc_help;

	rounder_double(mass, precision, (-1 * u));
	if ((int)precision > -1 * u)
		reculc_help = 0;
	else
		reculc_help = -1 * u - precision;
	while (reculc_help < (-1 * u) && mass[reculc_help] == 0)
		reculc_help++;
	return (-1 * u - reculc_help);
}

int		precision_recalculate(long double num,
		uintmax_t precision, Formatter *fr)
{
	int					i;
	int					mass[16500];
	int					u;
	union long_double	f;

	if (fr->flags[3] == '#')
		return (precision);
	i = 0;
	while (i < 16500)
	{
		mass[i] = 0;
		i++;
	}
	u = precision_recalculate_help_1(&f, mass, num);
	if (u < 0)
		return (precision_recalculate_help_2(precision, u, mass));
	return (precision);
}

int		precision_recalculate_help_3(long double num,
		uintmax_t precision, int *mass)
{
	int i;
	int reculc_help;

	reculc_help = 0;
	if (num > -1 && num < 1)
	{
		i = 16499;
		while (mass[i] == 0)
			i--;
		rounder_double(mass, precision, i);
	}
	i = 16499;
	while (mass[i] == 0)
		i--;
	if ((int)precision - 1 > i)
		reculc_help = 0;
	else
		reculc_help = i - precision + 1;
	while (mass[reculc_help] == 0 && reculc_help < i)
		reculc_help++;
	return (i - reculc_help);
}

int		precision_recalculate_1(long double num,
		uintmax_t precision, Formatter *fr)
{
	int					mass[16500];
	int					i;
	int					u;
	union long_double	f;

	if (fr->flags[3] == '#')
		return (precision - 1);
	if (precision == 0)
		return (0);
	i = 0;
	while (i < 16500)
	{
		mass[i] = 0;
		i++;
	}
	u = precision_recalculate_help_1(&f, mass, num);
	return (precision_recalculate_help_3(num, precision, mass));
}
