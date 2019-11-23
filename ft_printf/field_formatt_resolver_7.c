/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_7.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:27:44 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int			print_left_alignment_double(Formatter *fr,
		double i, uintmax_t number_length)
{
	int c;

	c = 0;
	if (i > 0 && fr->flags[1] == '+')
	{
		write(1, "+", 1);
		c++;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		c++;
	}
	display_double(i, fr->precision, fr);
	c += number_length;
	while (c < (int)fr->width - 1)
	{
		write(1, " ", 1);
		c++;
	}
	return (c);
}

int			print_double(Formatter *fr, double i,
		uintmax_t number_length, uintmax_t number_lenght_fact)
{
	int c;

	c = 0;
	if (fr->flags[4] != '0')
		while (c < (int)fr->width - (int)number_lenght_fact)
		{
			write(1, " ", 1);
			c++;
		}
	if (i < 0)
	{
		write(1, "-", 1);
		c++;
	}
	else if (fr->flags[1] == '+' && i >= 0)
	{
		write(1, "+", 1);
		c++;
	}
	if (fr->flags[4] == '0')
		print_long_double_1_1(fr, c, number_length);
	display_double(i, fr->precision, fr);
	return (c);
}

int		print_double_1(Formatter *fr, double i)
{
	int c;

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
	return (c + display_double(i, fr->precision, fr));
}

int		field_width_resolver_double(Formatter *fr, double i)
{
	uintmax_t number_length;
	uintmax_t number_lenght_fact;

	if (fr->precision == -1)
		fr->precision = 6;
	number_length = digit_counter_double(i, fr->precision, fr);
	number_lenght_fact = number_length_fact_double(fr, i, number_length);
	if (fr->width > number_lenght_fact)
	{
		if (fr->flags[0] == '-')
			return (print_left_alignment_double(fr, i, number_length));
		else
			return (print_double(fr, i, number_length, number_lenght_fact));
	}
	else
		return (print_double_1(fr, i));
}

uintmax_t	number_length_fact_e(Formatter *fr,
			uintmax_t number_length, long double i)
{
	uintmax_t number_lenght_fact;

	if ((fr->flags[1] == '+' || i < 0) && fr->precision != 0)
		number_lenght_fact = fr->precision + 5 + number_length;
	else if ((fr->flags[1] != '+') && fr->precision != 0)
		number_lenght_fact = fr->precision + 4 + number_length;
	else if (fr->precision == 0 && fr->flags[3] == '#' &&
			(fr->flags[1] == '+' || i < 0))
		number_lenght_fact = 5 + number_length;
	else if (fr->precision == 0 && fr->flags[3] == '#')
		number_lenght_fact = 4 + number_length;
	else if (fr->precision == 0 && (fr->flags[1] == '+' || i < 0))
		number_lenght_fact = 4 + number_length;
	else
		number_lenght_fact = 3 + number_length;
	return (number_lenght_fact);
}
