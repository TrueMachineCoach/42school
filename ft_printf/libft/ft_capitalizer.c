/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:17:35 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/17 16:21:14 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_capitalizer(char *str)
{
	int count_let;

	if (!str)
		return ;
	while (*str)
	{
		if (ft_is_space(*str))
			count_let = 0;
		else
			count_let++;
		if (count_let > 0)
			if (count_let == 1 && *str >= 'a' && *str <= 'z')
				ft_putchar(*str - 32);
			else if (count_let > 1 && *str >= 'A' && *str <= 'Z')
				ft_putchar(*str + 32);
			else
				ft_putchar(*str);
		else
			ft_putchar(*str);
		str++;
	}
}
