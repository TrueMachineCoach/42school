/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:32:02 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/11 16:43:10 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putposint(long n)
{
	if (n > 9)
		ft_putposint(n / 10);
	ft_putchar('0' + (n % 10));
}

void		ft_putnbr(int n)
{
	long num;

	num = n;
	if (n < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	ft_putposint(num);
}
