/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 19:46:46 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		validate_helper(char **str, int *k, int index, int detector)
{
	int j;

	j = 0;
	while (*str && **str && **str <= '9' && **str >= '0' && j < k[3])
	{
		k[index] = (k[index] * 10) + (**str - 48);
		if (!detector)
		{
			if (k[index] >= k[4])
				return (0);
		}
		else
		{
			if (k[index] > 31 ||
				(k[index] > 28 && k[index - 1] == 2) ||
					(k[index] > 30 && (k[index - 1] == 4 ||
						k[index] == 6 || k[index] == 9 || k[index] == 11)))
				return (0);
		}
		(*str)++ && j++;
	}
	if (j != k[3])
		return (0);
	return (1);
}

int		pprint_date(char *year, char *month, char *day)
{
	pprint_str(year, 4);
	write(1, "-", 1);
	pprint_str(month, 2);
	write(1, "-", 1);
	pprint_str(day, 2);
	return (10);
}

int		date_validation(char *year, char *month, char *day)
{
	int c[5];

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	c[3] = 4;
	c[4] = 10000;
	if (!validate_helper(&year, c, 0, 0))
		return (0);
	c[3] = 2;
	c[4] = 12;
	if (!validate_helper(&month, c, 1, 0))
		return (0);
	if (!validate_helper(&day, c, 2, 1))
		return (0);
	while (*day)
	{
		if (*day >= '0' && *day <= '9')
			return (0);
		day++;
	}
	return (1);
}

char	*parse_date(char **str, int k)
{
	char	*res;
	int		i;

	res = 0;
	i = 0;
	while (**str && i == 0)
	{
		if (**str >= '0' && **str <= '9')
		{
			res = *str;
			while (**str >= '0' && **str <= '9' && i < k && **str)
				(*str)++ && i++;
		}
		else
			(*str)++;
	}
	return (res);
}

int		print_date(Formatter *fr)
{
	char	*str;
	char	*year;
	char	*month;
	char	*day;
	int		i;

	i = 0;
	str = (char *)va_arg(*(fr->ap), char *);
	year = parse_date(&str, 4);
	month = parse_date(&str, 2);
	day = parse_date(&str, 2);
	if (!date_validation(year, month, day))
	{
		write(1, "Not valid date format", 21);
		return (21);
	}
	else
		return (pprint_date(year, month, day));
}
