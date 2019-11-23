/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:44:50 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/11 16:48:22 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putposint(long n, int fd)
{
	if (n > 9)
		ft_putposint(n / 10, fd);
	ft_putchar_fd('0' + (n % 10), fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	ft_putposint(num, fd);
}
