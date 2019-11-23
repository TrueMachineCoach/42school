/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:34:20 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 19:08:04 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	reverse_str(char *str)
{
	int		size;
	int		i;
	char	tmp;

	size = 0;
	while (str[size])
		size++;
	i = 0;
	size--;
	while (i < size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size] = tmp;
		size--;
		i++;
	}
}

size_t	itoa_base2(uintmax_t *tmp, int *base)
{
	size_t	i;

	i = 0;
	while ((*tmp) != 0)
	{
		(*tmp) /= (*base);
		i++;
	}
	return (i);
}

char	*itoa_base(uintmax_t num, int base, char spec)
{
	char		*result;
	uintmax_t	tmp;
	size_t		i;

	tmp = num;
	i = itoa_base2(&tmp, &base);
	if (!(result = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (num != 0)
	{
		if (num % base <= 9)
			result[i] = '0' + num % base;
		else if (spec == 'x')
			result[i] = 87 + num % base;
		else if (spec == 'X')
			result[i] = 55 + num % base;
		num /= base;
		i++;
	}
	result[i] = 0;
	reverse_str(result);
	return (result);
}

void	handle_data(Formatter *fr, uintmax_t i)
{
	char *str;

	if (fr->specifier == 'X')
		str = itoa_base(i, 16, 'X');
	if (fr->specifier == 'x')
		str = itoa_base(i, 16, 'x');
	if (fr->specifier == 'o')
		str = itoa_base(i, 8, 'o');
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	if (i == 0 && fr->precision != 0)
		write(1, "0", 1);
	else
		write(1, " ", 1);	
}
