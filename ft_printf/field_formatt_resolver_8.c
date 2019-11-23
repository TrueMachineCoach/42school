/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_8.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:40:18 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int		print_e_left_alignment(Formatter *fr,
		long double i, uintmax_t number_lenght_fact)
{
	int c;

	c = 0;
	if (i > 0 && fr->flags[1] == '+')
		write(1, "+", 1);
	if (i < 0)
		write(1, "-", 1);
	display_long_double_eE(i, fr->precision, fr, digit_counter_e_1(i, fr));
	c += number_lenght_fact;
	while (c < (int)fr->width)
	{
		write(1, " ", 1);
		c++;
	}
	return (c);
}

int		print_e(Formatter *fr, long double i, uintmax_t number_lenght_fact)
{
	int c;

	c = 0;
	if (fr->flags[4] != '0')
		while (c < (int)fr->width - (int)number_lenght_fact)
			write(1, " ", 1) && c++;
	if (i < 0)
		write(1, "-", 1);
	else if (fr->flags[1] == '+' && i > 0)
		write(1, "+", 1);
	if (fr->flags[4] == '0')
		while (c < (int)fr->width - (int)number_lenght_fact)
		{
			write(1, "0", 1);
			c++;
		}
	display_long_double_eE(i, fr->precision, fr, digit_counter_e_1(i, fr));
	return (c + (int)number_lenght_fact);
}

int		print_e_1(Formatter *fr, long double i,
		uintmax_t number_lenght_fact)
{
	int c;

	c = 0;
	if (fr->flags[1] == '+' && i > 0)
	{
		write(1, "+", 1);
		c = 1;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		c = 1;
	}
	display_long_double_eE(i, fr->precision, fr, digit_counter_e_1(i, fr));
	return (c + (int)number_lenght_fact);
}

int		field_width_resolver_e(Formatter *fr, long double i)
{
	uintmax_t number_length;
	uintmax_t number_lenght_fact;

	if (inf_nan_detector_long_double(i))
		return (print_nan_inf(fr, inf_nan_detector_long_double(i)));
	if (fr->precision == -1)
		fr->precision = 6;
	number_length = digit_counter_e(i, fr);
	if (number_length == 1)
		number_length++;
	number_lenght_fact = number_length_fact_e(fr, number_length, i);
	if (fr->width > number_lenght_fact)
	{
		if (fr->flags[0] == '-')
			return (print_e_left_alignment(fr, i, number_lenght_fact));
		else
			return (print_e(fr, i, number_lenght_fact));
	}
	else
		return (print_e_1(fr, i, number_lenght_fact));
}

int		field_width_resolver_e_double(Formatter *fr, double i)
{
	uintmax_t number_length;
	uintmax_t number_lenght_fact;

	if (inf_nan_detector_double(i))
		return (print_nan_inf(fr, inf_nan_detector_double(i)));
	if (fr->precision == -1)
		fr->precision = 6;
	number_length = digit_counter_e((long double)i, fr);
	if (number_length == 1)
		number_length++;
	number_lenght_fact = number_length_fact_e(fr, number_length, i);
	if (fr->width > number_lenght_fact)
	{
		if (fr->flags[0] == '-')
			return (print_e_left_alignment(fr, i, number_lenght_fact));
		else
			return (print_e(fr, i, number_lenght_fact));
	}
	else
		return (print_e_1(fr, i, number_lenght_fact));
}