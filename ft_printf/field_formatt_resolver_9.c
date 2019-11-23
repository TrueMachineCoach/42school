/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_9.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/22 16:09:22 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

uintmax_t	number_length_fact_e_1(Formatter *fr,
			uintmax_t number_length, double i)
{
	uintmax_t number_lenght_fact;

	if ((fr->flags[1] == '+' || i < 0) && fr->precision != 0)
		number_lenght_fact = fr->precision + 5 + number_length;
	else if ((fr->flags[1] != '+') && fr->precision != 0)
		number_lenght_fact = fr->precision + 4 + number_length;
	else if (fr->precision == 0 && fr->flags[3] == '#')
		number_lenght_fact = 4 + number_length;
	else
		number_lenght_fact = 3 + number_length;
	return (number_lenght_fact);
}

void		field_width_resolver_e_double_1(Formatter *fr, double i)
{
	uintmax_t number_length;
	uintmax_t number_lenght_fact;

	if (fr->precision == -1)
		fr->precision = 6;
	number_length = digit_counter_e(i, fr);
	if (number_length == 1)
		number_length++;
	number_lenght_fact = number_length_fact_e_1(fr, number_length, i);
	if (fr->width > number_lenght_fact)
	{
		if (fr->flags[0] == '-')
			print_e_left_alignment(fr, i, number_lenght_fact);
		else
			print_e(fr, i, number_lenght_fact);
	}
	else
		print_e_1(fr, i);
}

int			precision_recalculate_2_helper_1(int *mass,
		union long_double *f, long double num, uintmax_t precision)
{
	intmax_t	i;
	int			u;

	f->f = num;
	i = 0;
	while (i < 16500)
	{
		mass[i] = 0;
		i++;
	}
	u = f->bin.exp - 16383 - 63;
	put_in_intmass(mass, f->bin.frac);
	i = 0;
	while (i < (-1 * u))
	{
		intmass_multiply(mass, 5);
		i++;
	}
	i = 16499;
	while (mass[i] == 0)
		i--;
	rounder_double(mass, precision, i);
	return (u);
}

int			precision_recalculate_2_helper_2(Formatter *fr,
		int *c, long double num, int *mass)
{
	int reculc_help;
	int reculc_help_2;

	reculc_help = 0;
	reculc_help_2 = 0;
	while (mass[c[0]] == 0)
	{
		c[0]--;
		reculc_help++;
		reculc_help_2++;
	}
	if (fr->flags[3] == '#' && num < 1 && num > -1)
		return (c[1] + reculc_help_2 - 1);
	while (reculc_help < reculc_help_2 + c[1] - 1 && c[0] > 0)
	{
		c[0]--;
		reculc_help++;
	}
	while (mass[c[0]] == 0)
	{
		c[0]++;
		reculc_help--;
	}
	return (reculc_help_helper(fr, reculc_help));
}

int			precision_recalculate_2(long double num,
		uintmax_t precision, Formatter *fr)
{
	int					mass[16500];
	int					c[2];
	union long_double	f;

	if (fr->flags[3] == '#' && (num > 1 || num < -1))
		return (precision - 1);
	c[0] = -1 * precision_recalculate_2_helper_1(mass, &f, num, precision);
	c[1] = precision;
	return (precision_recalculate_2_helper_2(fr, c, num, mass));
}
