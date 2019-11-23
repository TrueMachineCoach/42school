/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:42:26 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 19:52:59 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		pprint_str(char *str, size_t size)
{
	size_t length;

	length = ft_strlen(str);
	if (size <= length)
	{
		write(1, str, size);
		return (size);
	}
	else
	{
		write(1, str, length);
		return (length);
	}
}

int		print_str(Formatter *fr)
{
	char	*str;
	int		i;
	int j;
	size_t	length;

	str = va_arg(*fr->ap, char*);
	length = ft_strlen(str);
	i = 0;
	if (fr->flags[0] == '-' && (int)fr->width > (int)length)
	{
		j = pprint_str(str, fr->precision);
		while (i < ((int)fr->width - (fr->precision <= (int)length ?
				(int)fr->precision : (int)length)))
			write(1, " ", 1) && i++;
		return (i + j);
	}
	else if (fr->width > length)
	{
		while (i < ((int)fr->width - (fr->precision <= (int)length ?
				(int)fr->precision : (int)length)))
			write(1, " ", 1) && i++;
		return (i + pprint_str(str, fr->precision));
	}
	else
		return (i + pprint_str(str, fr->precision));
}

int		print_char(Formatter *fr)
{
	char	sym;
	int		i;

	sym = (char)va_arg(*fr->ap, int);
	i = 0;
	if (fr->flags[0] == '-')
	{
		write(1, &sym, 1);
		while (i < ((int)fr->width - 1))
			write(1, " ", 1) && i++;
	}
	else
	{
		while (i < ((int)fr->width - 1))
			write(1, " ", 1) && i++;
		write(1, &sym, 1);
	}
	return (i);
}
