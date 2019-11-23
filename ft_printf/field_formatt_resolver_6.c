/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_6.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:21:14 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int		print_left_alignment_long_double(Formatter *fr,
		long double i, uintmax_t number_length)
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
	display_long_double(i, fr->precision, fr);
	c += number_length;
	while (c < (int)fr->width - 1)
	{
		write(1, " ", 1);
		c++;
	}
	return (c);
}

int		print_long_double_1(Formatter *fr, long double i)
{
	int i;
	
	i = 0;
	if (fr->flags[1] == '+' && i > 0)
	{
		write(1, "+", 1);
		i = 1;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i = 1;
	}
	return (i + display_long_double(i, fr->precision, fr));
}

int		print_long_double_1_1(Formatter *fr, int c, uintmax_t number_length)
{
	while (c < (int)fr->width - (int)number_length - 1)
	{
		write(1, "0", 1);
		c++;
	}
	return (c);
}

int		print_long_double(Formatter *fr,
		long double i, uintmax_t number_length, uintmax_t number_lenght_fact)
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
		c += print_long_double_1_1(fr, c, number_length);
	return (c + display_long_double(i, fr->precision, fr));
}

int 	field_width_resolver_long_double(Formatter *fr, long double i)
{
	uintmax_t number_length;
	uintmax_t number_lenght_fact;

	if (fr->precision == -1)
		fr->precision = 6;
	number_length = digit_counter_long_double(i, fr->precision, fr);
	number_lenght_fact = number_length_fact_double(fr, i, number_length);
	if (fr->width > number_lenght_fact)
	{
		if (fr->flags[0] == '-')
			return (print_left_alignment_long_double(fr, i, number_length));
		else
			return (print_long_double(fr, i, number_length, number_lenght_fact));
	}
	else
		return (print_long_double_1(fr, i));
}
