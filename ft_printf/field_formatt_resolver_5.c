/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_5.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 19:32:18 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int			hash_detector_ox(Formatter *fr, int c, uintmax_t i)
{
	if (fr->flags[3] == '#' && fr->specifier == 'o' && i != 0)
	{
		write(1, "0", 1);
		c++;
	}
	if (fr->flags[3] == '#' && fr->specifier == 'x' && i != 0)
	{
		write(1, "0x", 2);
		c += 2;
	}
	if (fr->flags[3] == '#' && fr->specifier == 'X' && i != 0)
	{
		write(1, "0X", 2);
		c += 2;
	}
	if (i == 0)
	{
		if (fr->flags[0] != '-' && fr->precision != 0)
		{
			write(1, "  ", 2);
			c += 2;
		}
	}
	return (c);
}

void		print_left_alignment_ox(Formatter *fr,
		uintmax_t i, int number_length)
{
	int count_prec;
	int c;

	c = 0;
	count_prec = 0;
	c = hash_detector_ox(fr, c, i);
	while (count_prec < fr->precision - number_length)
	{
		write(1, "0", 1);
		c++;
		count_prec++;
	}
	handle_data(fr, i);
	c += number_length;
	while (c < (int)fr->width)
	{
		write(1, " ", 1);
		c++;
	}
}

void		print_not_zero_p_ox(Formatter *fr,
		int number_length, uintmax_t number_lenght_fact, uintmax_t i)
{
	int c;

	c = 0;
	if (fr->precision >= 0 && fr->width > number_lenght_fact)
		while (c < (int)fr->width - (int)number_lenght_fact)
		{
			write(1, " ", 1);
			c++;
		}
	if (fr->precision < 0 && fr->width > number_lenght_fact)
		while (c < (int)fr->width - (int)number_lenght_fact && fr->flags[4] != '0')
		{
			write(1, " ", 1);
			c++;
		}
	c = hash_detector_ox(fr, c, i);
	while (c < (int)fr->width - (int)number_length)
	{
		write(1, "0", 1);
		c++;
	}
	handle_data(fr, i);
}

int		field_width_resolver_ox(Formatter *fr, uintmax_t i)
{
	int			base;
	int			number_length;
	uintmax_t	number_lenght_fact;

	if (fr->specifier == 'o')
		base = 8;
	else
		base = 16;
	number_length = number_length_counter_unsigned(i, base);
	number_lenght_fact = number_lenght_fact_ox(fr, number_length);
	if (fr->width > number_lenght_fact)
	{
		if (fr->flags[0] == '-')
			return (print_left_alignment_ox(fr, i, number_length));
		else
		{
			if (fr->precision >= 0)
				return (print_not_zero_p_ox(fr, number_length,
					number_lenght_fact, i));
			else
				return (print_not_zero_p_ox(fr, number_length, number_lenght_fact, i));
		}
	}
	else
		return (print_not_zero_p_ox(fr, number_length, number_lenght_fact, i));
}

uintmax_t	number_length_fact_double(Formatter *fr,
		long double i, uintmax_t number_length)
{
	uintmax_t number_lenght_fact;

	number_lenght_fact = number_length;
	if (fr->flags[1] == '+' || i < 0)
		number_lenght_fact += 1;
	if (fr->flags[3] == '#' && fr->precision == 0)
		number_lenght_fact += 1;
	if (fr->flags[3] != '#' && fr->precision == 0)
		number_length -= 1;
	if (fr->precision > 0)
		number_lenght_fact += 1;
	return (number_lenght_fact);
}
