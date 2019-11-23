/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_non_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:49:55 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:07:36 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	dec_to_hex2(int *i, int *k, char *str, char *c)
{
	while ((*i) < (*k))
	{
		str[(*i)] = (*c) % 16;
		if (str[(*i)] >= 10)
			str[(*i)] = str[(*i)] + 87;
		else
			str[(*i)] = str[(*i)] + '0';
		(*c) = (*c) / 16;
		(*i)++;
	}
}

char	*dec_to_hex(char c)
{
	int		k;
	int		i;
	char	buff;
	char	*str;

	buff = c;
	i = 0;
	while (buff / 16)
	{
		i++;
		buff = buff / 16;
	}
	i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	k = i;
	i = 0;
	dec_to_hex2(&i, &k, str, &c);
	str[i] = 0;
	return (str);
}

int		print_non_printable(char *str)
{
	int i;
	
	i = 0;
	while (*str)
	{
		if (*str < 16 && *str >= 0)
		{
			write(1, "\\x0", 3);
			write(1, dec_to_hex(*str), 2);
		}
		if (*str >= 16 && *str < 32)
		{
			write(1, "\\x", 2);
			write(1, dec_to_hex(*str), 3);
		}
		str++;
		i++;
	}
	write(1, "\\x00", 4);
	return (i * 5 + 4);
}
