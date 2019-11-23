/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:46:11 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int		router_1(int digit_amount, Formatter *fr, double i)
{
	if (digit_amount < -4 && i != 0)
	{
		fr->precision = precision_recalculate_1(i, fr->precision, fr);
		return (field_width_resolver_e_double(fr, i));
	}
	else if (digit_amount <= 0 && digit_amount >= -4)
	{
		fr->precision = precision_recalculate_2((long double)i,
						fr->precision, fr);
		return (field_width_resolver_double(fr, i));
	}
	else if (fr->precision <= digit_amount)
	{
		fr->precision = precision_recalculate_1((long double)i,
						fr->precision, fr);
		return (field_width_resolver_e_double(fr, i));
	}
	else
	{
		if (i == 0)
		{
			if (fr->precision != 0)
				fr ->precision -= 1;
		}
		else
			fr->precision = precision_recalculate((long double)i,
								fr->precision - digit_amount - 1, fr);
		return (field_width_resolver_double(fr, i));
	}
}

int 	field_width_resolver_g_double(Formatter *fr, double i)
{
	int digit_amount;

	if (inf_nan_detector_double(i))
		return (print_nan_inf(fr, inf_nan_detector_double(i)));
	if (fr->precision == -1)
		fr->precision = 6;
	digit_amount = digit_counter_e_2((long double)i, fr);
	return (router_1(digit_amount, fr, i));
}

int		router_2(int digit_amount, Formatter *fr, long double i)
{
	if (digit_amount < -4 && i != 0)
	{
		fr->precision = precision_recalculate_1(i, fr->precision, fr);
		return (field_width_resolver_e(fr, i));
	}
	else if (digit_amount <= 0 && digit_amount >= -4)
	{
		fr->precision = precision_recalculate_2(i, fr->precision, fr);
		return (field_width_resolver_long_double(fr, i));
	}
	else if (fr->precision <= digit_amount)
	{
		fr->precision = precision_recalculate_1(i, fr->precision, fr);
		return (field_width_resolver_e(fr, i));
	}
	else
	{
		if (i == 0)
		{
			if (fr->precision != 0)
				fr ->precision -= 1;
		}
		else
			fr->precision = precision_recalculate(i,
							fr->precision - digit_amount - 1, fr);
		return (field_width_resolver_long_double(fr, i));
	}
}

int		field_width_resolver_g_long_double(Formatter *fr, long double i)
{
	int digit_amount;

	digit_amount = digit_counter_e_2(i, fr);
	if (fr->precision == -1)
		fr->precision = 6;
	if (inf_nan_detector_long_double(i))
		return (print_nan_inf(fr, inf_nan_detector_long_double(i)));
	return (router_2(digit_amount, fr, i));
}
