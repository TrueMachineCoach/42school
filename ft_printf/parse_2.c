/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:11:22 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/12 20:44:52 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list		*parse_baks(Formatter *fr, va_list *args)
{
	size_t k;
	size_t i;
	size_t j;

	i = 0;
	k = 1;
	j = fr->c;
	while ('0' <= fr->str[j] && fr->str[j] <= '9')
	{
		i = (i * 10) + (fr->str[j] - '0');
		j++;
	}
	if (fr->str[j] == '$')
	{
		while (k < i)
		{
			va_arg(*args, int);
			k++;
		}
		fr->baks = i;
		fr->c = ++j;
		return (args);
	}
	return (0);
}

void		parse_flags(Formatter *fr)
{
	char	*mask;
	int		i;

	mask = "-+ #0";
	i = 0;
	while (mask[i])
	{
		if (fr->str[fr->c] == '-' || fr->str[fr->c] == '+' ||
		fr->str[fr->c] == ' ' || fr->str[fr->c] == '#' || fr->str[fr->c] == '0')
		{
			while (fr->str[fr->c] == '-' && (fr->flags[0] = '-'))
				fr->c++;
			while (fr->str[fr->c] == '+' && (fr->flags[1] = '+'))
				fr->c++;
			while (fr->str[fr->c] == ' ' && (fr->flags[2] = ' '))
				fr->c++;
			while (fr->str[fr->c] == '#' && (fr->flags[3] = '#'))
				fr->c++;
			while (fr->str[fr->c] == '0' && (fr->flags[4] = '0'))
				fr->c++;
			i = 0;
		}
		else
			i++;
	}
}
