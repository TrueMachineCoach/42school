/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:23:58 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/16 11:56:03 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_size_num(long n)
{
	int count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	long	num;
	int		sign;
	char	*result;
	int		i;

	num = n;
	sign = 0;
	if (num < 0)
	{
		sign = 1;
		num *= -1;
	}
	result = ft_strnew(ft_count_size_num(num) + sign);
	if (result)
	{
		i = ft_count_size_num(num) + sign - 1;
		while (i >= 0)
		{
			result[i--] = '0' + num % 10;
			num /= 10;
		}
		if (sign)
			result[i + 1] = '-';
	}
	return (result);
}
