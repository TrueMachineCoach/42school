/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_4.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:53:44 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

void		print_positive_precision_signed(Formatter *fr,
		intmax_t i, int number_length)
{
	int c;

	c = 0;
	if (fr->precision > number_length)
		while (c < (int)fr->width - (int)fr->precision - 1)
		{
			write(1, " ", 1);
			c++;
		}
	else
		while (c < (int)fr->width - (int)number_length - 1)
		{
			write(1, " ", 1);
			c++;
		}
	print_positive_presision_signed_helper(fr, i, c, number_length);
}

void		print_sign(Formatter *fr,
	uintmax_t number_lenght_fact, intmax_t i)
{
	int c;

	c = 0;
	if (i < 0 && fr->flags[4] == '0')
		write(1, "-", 1);
	if (fr->flags[1] == '+' && i > 0 && fr->flags[4] == '0')
		write(1, "+", 1);
	while (c <= (int)fr->width - (int)number_lenght_fact - 1)
	{
		if (fr->flags[4] == '0')
			write(1, "0", 1);
		else
			write(1, " ", 1);
		c++;
	}
	if (i < 0)
		write(1, "-", 1 && fr->flags[4] != '0');
	if (fr->flags[1] == '+' && i > 0 && fr->flags[4] != '0')
		write(1, "+", 1);
}

void		print_zero_precision_signed(Formatter *fr,
	uintmax_t number_lenght_fact, intmax_t i, int number_length)
{
	int c;

	c = 0;
	if (fr->width > number_lenght_fact)
		print_sign(fr, number_lenght_fact, i);
	else
	{
		if (fr->flags[1] == '+' && i > 0)
			write(1, "+", 1);
		if (i < 0)
			write(1, "-", 1);
		while (c < fr->precision - number_length)
		{
			write(1, "0", 1);
			c++;
		}
	}
	display_diu_signed(fr, i);
}

int			field_width_resolver(Formatter *fr, intmax_t i)
{
	int			number_length;
	uintmax_t	number_lenght_fact;

	number_length = number_length_counter_unsigned((i < 0 ? i * -1 : i), 10);
	number_lenght_fact = number_lenght_fact_signed(fr, number_length, i);
	if (fr->width > number_lenght_fact)
	{
		if (fr->flags[0] == '-')
			return (print_signed_left_alignment(fr, number_length, i));
		else
		{
			if (fr->precision >= 0)
				return (print_positive_precision_signed(fr, i, number_length));
			else
				return (print_zero_precision_signed(fr, number_lenght_fact,
					i, number_length));
		}
	}
	else
		return (print_zero_precision_signed(fr, number_lenght_fact, i, number_length));
}

uintmax_t	number_lenght_fact_ox(Formatter *fr, int number_length)
{
	uintmax_t number_lenght_fact;

	if (fr->precision > number_length)
	{
		number_lenght_fact = fr->precision;
		if (fr->flags[3] == '#' && fr->specifier == 'o')
			number_lenght_fact++;
		if (fr->flags[3] == '#' && (fr->specifier == 'x'
				|| fr->specifier == 'X'))
			number_lenght_fact += 2;
	}
	else
	{
		number_lenght_fact = number_length;
		if (fr->flags[3] == '#' && fr->specifier == 'o')
			number_lenght_fact++;
		if (fr->flags[3] == '#' && (fr->specifier == 'x'
				|| fr->specifier == 'X'))
			number_lenght_fact += 2;
	}
	return (number_lenght_fact);
}
