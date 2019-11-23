/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:11:22 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 16:48:15 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_width(Formatter *fr, va_list *args)
{
	fr->width = 0;
	while ('0' <= fr->str[fr->c] && fr->str[fr->c] <= '9')
	{
		fr->width = (fr->width * 10) + (fr->str[fr->c] - '0');
		fr->c++;
	}
	if (fr->str[fr->c] == '*')
	{
		fr->width = (size_t)va_arg(*args, int);
		fr->c++;
		return (1);
	}
	return (0);
}

int		parse_precision(Formatter *fr, va_list *args)
{
	if (fr->str[fr->c] == '.')
	{
		fr->precision = 0;
		fr->c++;
		while ('0' <= fr->str[fr->c] && fr->str[fr->c] <= '9')
		{
			fr->precision = (fr->precision * 10) + (fr->str[fr->c] - '0');
			fr->c++;
		}
		if (fr->str[fr->c] == '*')
		{
			fr->precision = (size_t)va_arg(*args, int);
			fr->c++;
			return (1);
		}
	}
	return (0);
}

void	parse_specifier(Formatter *fr)
{
	fr->specifier = fr->str[fr->c];
	fr->c++;
}

void	parse_length(Formatter *fr)
{
	int i;

	i = 0;
	while (fr->str[fr->c] != 'd' && fr->str[fr->c] != 'i'
		&& fr->str[fr->c] != 'o' && fr->str[fr->c] != 'u'
		&& fr->str[fr->c] != 'x' && fr->str[fr->c] != 'X'
		&& fr->str[fr->c] != 'e' && fr->str[fr->c] != 'g'
		&& fr->str[fr->c] != 'f' && fr->str[fr->c] != 'F'
		&& fr->str[fr->c] != 'r' && fr->str[fr->c] != 'E'
		&& fr->str[fr->c] != 'G' && fr->str[fr->c] != 'k'
		&& fr->str[fr->c] != 'c' && fr->str[fr->c] != 's'
		&& fr->str[fr->c] != 'p' && fr->str[fr->c] != '%')
	{
		fr->length[i] = fr->str[fr->c];
		i++;
		fr->c++;
	}
}

int		parse(Formatter *fr, va_list *args)
{
	va_list *copy_args2;
	va_list copy_args;

	va_copy(copy_args, *args);
	fr->c++;
	if ((copy_args2 = parse_baks(fr, &copy_args)))
		args = copy_args2;
	fr->ap = args;
	parse_flags(fr);
	parse_width(fr, args);
	parse_precision(fr, args);
	parse_length(fr);
	parse_specifier(fr);
	resolver(fr);
	if (copy_args2)
		return (1);
	return (0);
}
