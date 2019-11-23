/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:26:08 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/22 19:27:03 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_binary2(uintmax_t nb)
{
	char c;

	if (nb == 1)
	{
		write(1, "1", 1);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb > 2)
	{
		print_binary2(nb / 2);
		c = '0' + nb % 2;
		write(1, &c, 1);
		return ;
	}
	c = '0' + nb / 2;
	write(1, &c, 1);
	c = '0' + nb % 2;
	write(1, &c, 1);
}
