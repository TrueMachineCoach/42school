/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 19:59:07 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int		print_unsigned_left_alignment(Formatter *fr,
		int number_length, uintmax_t i)
{
	int count_prec;
	int c;

	c = 0;
	if (fr->flags[1] == '+')
	{
		write(1, "+", 1);
		c++;
	}
	count_prec = 0;
	while (count_prec < fr->precision - number_length)
	{
		write(1, "0", 1);
		c++;
		count_prec++;
	}
	display_diu_unsigned(i);
	c += number_length;
	while (c < (int)fr->width)
	{
		write(1, " ", 1);
		c++;
	}
	return (c);
}

int		print_unsigned_positive_precision(Formatter *fr,
		int number_length, uintmax_t i)
{
	int c;

	c = 0;
	if (fr->precision > number_length)
		while (c < (int)fr->width - fr->precision)
		{
			write(1, " ", 1);
			c++;
		}
	else
		while (c < (int)fr->width - number_length)
		{
			write(1, " ", 1);
			c++;
		}
	while (c < (int)fr->width - number_length)
	{
		write(1, "0", 1);
		c++;
	}
	return (c + display_diu_unsigned(i));
}

int		print_last(Formatter *fr,
		uintmax_t number_length, uintmax_t i, int indic)
{
	int c;

	c = 0;
	if (indic == 0)
		while (c <= (int)fr->width - (int)number_length - 1)
		{
			if (fr->flags[4] == '0')
				write(1, "0", 1);
			else
				write(1, " ", 1);
			c++;
		}
	else
		while (c < fr->precision - (int)number_length)
		{
			write(1, "0", 1);
			c++;
		}
	return (c + display_diu_unsigned(i));
}

int		field_width_resolver_unsigned(Formatter *fr, uintmax_t i)
{
	int			number_length;
	uintmax_t	number_lenght_fact;

	number_length = number_length_counter_unsigned(i, 10);
	number_lenght_fact = number_lenght_fact_definer_unsigned(fr, number_length);
	if ((int)fr->width > (int)number_lenght_fact)
	{
		if (fr->flags[0] == '-')
			return (print_unsigned_left_alignment(fr, number_length, i));
		else
		{
			if (fr->precision >= 0)
				return (print_unsigned_positive_precision(fr, number_length, i));
			else
				return (print_last(fr, number_lenght_fact, i, 0));
		}
	}
	else
		return (print_last(fr, number_length, i, 1));
}

void	print_positive_presision_signed_helper(Formatter *fr,
		intmax_t i, int c, int number_length)
{
	if (i < 0)
	{
		write(1, "-", 1);
		c++;
	}
	else if (fr->flags[1] == '+' && i > 0)
	{
		write(1, "+", 1);
		c++;
	}
	else
	{
		write(1, " ", 1);
		c++;
	}
	while (c < (int)fr->width - number_length)
	{
		write(1, "0", 1);
		c++;
	}
	display_diu_signed(fr, i);
}
