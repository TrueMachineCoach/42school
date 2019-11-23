/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 13:49:56 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

uintmax_t	number_lenght_fact_signed(Formatter *fr,
			int number_length, intmax_t i)
{
	uintmax_t number_lenght_fact;

	if (fr->precision > number_length)
	{
		if (fr->flags[1] == '+' || i < 0)
			number_lenght_fact = fr->precision + 1;
		else
			number_lenght_fact = fr->precision;
	}
	else
	{
		if (fr->flags[1] == '+' || i < 0)
			number_lenght_fact = number_length + 1;
		else
			number_lenght_fact = number_length;
	}
	return (number_lenght_fact);
}

uintmax_t	number_lenght_fact_definer_unsigned(Formatter *fr,
			int number_length)
{
	uintmax_t number_lenght_fact;

	if (fr->precision > number_length)
	{
		if (fr->flags[1] == '+')
			number_lenght_fact = fr->precision + 1;
		else
			number_lenght_fact = fr->precision;
	}
	else
	{
		if (fr->flags[1] == '+')
			number_lenght_fact = number_length + 1;
		else
			number_lenght_fact = number_length;
	}
	return (number_lenght_fact);
}

int			number_length_counter_unsigned(uintmax_t i, int base)
{
	int			number_length;
	uintmax_t	k;

	k = i;
	number_length = 0;
	while (k / base > 0)
	{
		k = k / base;
		number_length++;
	}
	number_length++;
	return (number_length);
}

void		print_left_alignment_help(Formatter *fr,
			int number_length, int c)
{
	c += number_length;
	while (c < (int)fr->width)
	{
		write(1, " ", 1);
		c++;
	}
}

void		print_signed_left_alignment(Formatter *fr,
			int number_length, intmax_t i)
{
	int		count_prec;
	int		c;

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
	count_prec = 0;
	while (count_prec < fr->precision - number_length)
	{
		write(1, "0", 1);
		c++;
		count_prec++;
	}
	display_diu_signed(fr, i);
	print_left_alignment_help(fr, number_length, c);
}
