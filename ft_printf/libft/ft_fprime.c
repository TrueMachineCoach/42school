/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:58:27 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/17 11:18:19 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fprime(unsigned int num)
{
	int divisor;
	int amoun_factor;

	if (num == 0 || num == 1)
	{
		ft_putnbr(num);
		ft_putchar('\n');
		return ;
	}
	divisor = 2;
	amoun_factor = 0;
	while (num != 1)
	{
		while (num % divisor == 0)
		{
			if (amoun_factor > 0)
				ft_putchar('*');
			ft_putnbr(divisor);
			num /= divisor;
			amoun_factor++;
		}
		divisor++;
	}
	ft_putchar('\n');
}
