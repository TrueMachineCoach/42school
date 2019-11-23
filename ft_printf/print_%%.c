/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_%%.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:57:06 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 17:01:52 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_percent(Formatter *fr)
{
	int c;

	c = 0;
	if (fr->flags[0] == '-')
	{
		write(1, "%", 1);
		while(c < (int)fr->width - 1)
		{
		if (fr->flags[4] == '0')
			write(1, "0", 1);
		else
			write(1, " ", 1);
		c++;
		}
	}
	else
	{
		while(c < (int)fr->width - 1)
		{
			if (fr->flags[4] == '0')
				write(1, "0", 1);
			else
				write(1, " ", 1);
			c++;
		}
		write(1, "%", 1);
	}
	// c++;
	return(c);
}
