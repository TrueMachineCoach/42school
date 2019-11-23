/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_diouxX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:57:06 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:47:52 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <float.h>
#include <unistd.h>
#include <math.h>

int		resolver_diu(Formatter *fr)
{
	uintmax_t ui;

	ui = 0;
	if (fr->specifier == 'u')
	{
		if (ft_strcmp(fr->length, "hh") == 0)
			ui = (unsigned char)(va_arg(*(fr->ap), unsigned int));
		else if (!(ft_strcmp(fr->length, "h")))
			ui = (short)(va_arg(*(fr->ap), unsigned int));
		else if (!(ft_strcmp(fr->length, "l")))
			ui = (unsigned long)(va_arg(*(fr->ap), unsigned long));
		else if (!(ft_strcmp(fr->length, "ll")))
			ui = (unsigned long long)(va_arg(*(fr->ap), unsigned long long));
		else
			ui = (unsigned int)(va_arg(*(fr->ap), unsigned int));
		return (field_width_resolver_unsigned(fr, ui));
	}
	else
		return (resolver_diu2(&ui, fr));
}

int		resolve_non_printable(Formatter *fr)
{
	char *str;

	str = (char *)va_arg(*(fr->ap), char *);
	return (print_non_printable(str));
}

int		resolve_float(Formatter *fr)
{
	double		tmp;
	long double	tmp1;

	if (!(ft_strcmp(fr->length, "L")))
	{
		tmp1 = (long double)va_arg(*(fr->ap), long double);
		if (inf_nan_detector_long_double(tmp1) != 0)
			return (print_nan_inf(fr, inf_nan_detector_long_double(tmp1)));
		else
			return (field_width_resolver_long_double(fr, tmp1));
	}
	else
	{
		tmp = (double)va_arg(*(fr->ap), double);
		if (inf_nan_detector_double(tmp))
			return (print_nan_inf(fr, inf_nan_detector_double(tmp)));
		else
			return (field_width_resolver_double(fr, tmp));
	}
}

int		resolve_eegg(Formatter *fr)
{
	if ((fr->specifier == 'e' || fr->specifier == 'E')
					&& (ft_strcmp(fr->length, "L") == 0))
		return (field_width_resolver_e(fr, (long double)va_arg(*(fr->ap),
					long double)));
	if ((fr->specifier == 'e' || fr->specifier == 'E')
					&& (ft_strcmp(fr->length, "L") != 0))
		return (field_width_resolver_e_double(fr, (double)va_arg(*(fr->ap),
					double)));
	if ((fr->specifier == 'g' || fr->specifier == 'G')
					&& (ft_strcmp(fr->length, "L") != 0))
		return (field_width_resolver_g_double(fr, (double)va_arg(*(fr->ap),
					double)));
	if ((fr->specifier == 'g' || fr->specifier == 'G')
					&& (ft_strcmp(fr->length, "L") == 0))
		return (field_width_resolver_g_long_double(fr,
					(long double)va_arg(*(fr->ap), long double)));
}

int		resolver(Formatter *fr)
{
	if (fr->specifier == 'd' || fr->specifier == 'i' ||
			fr->specifier == 'u')
		return (resolver_diu(fr));
	if (fr->specifier == 'x' || fr->specifier == 'X' || fr->specifier == 'o')
		return (field_width_resolver_ox(fr, (uintmax_t)va_arg(*(fr->ap), uintmax_t)));
	if (fr->specifier == 'e' || fr->specifier == 'E' ||
			fr->specifier == 'g' || fr->specifier == 'G')
		return (resolve_eegg(fr));
	if (fr->specifier == 'f' || fr->specifier == 'F')
		return (resolve_float(fr));
	if (fr->specifier == 'r')
		return (resolve_non_printable(fr));
	if (fr->specifier == 'k')
		return (print_date(fr));
	if (fr->specifier == 'c')
		return (print_char(fr));
	if (fr->specifier == 's')
		return (print_str(fr));
	if (fr->specifier == 'p')
		return (print_pointer(fr));
	if (fr->specifier == '%')
		return (print_percent(fr));
	return (0);
}
