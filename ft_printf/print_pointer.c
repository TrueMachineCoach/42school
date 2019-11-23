/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:20:07 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 19:54:17 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

int		print_pointer(Formatter *fr)
{
	void	*p;
	int		i;
	char	*str;
	int		size;

	p = va_arg(*fr->ap, void *);
	if (!(str = itoa_base((uintmax_t)p, 16, 'x')))
		return ;
	size = ft_strlen(str);
	i = 0;
	if (fr->flags[0] == '-')
	{
		write(1, "0x", 2);
		write(1, str, size);
		while (i < (int)fr->width - size - 2)
			write(1, " ", 1) && i++;
		return (i + 3);
	}
	else
	{
		while (i < (int)fr->width - size - 2)
			write(1, " ", 1) && i++;
		write(1, "0x", 2);
		write(1, str, size);
		return (i + 3);
	}
}
