/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_diouxx2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:50:19 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:02:26 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <float.h>
#include <unistd.h>
#include <math.h>

static void	ft_putpos_int(uintmax_t n)
{
	if (n > 9)
		ft_putpos_int(n / 10);
	ft_putchar('0' + (n % 10));
}

void		display_diu_unsigned(uintmax_t i)
{
	ft_putpos_int(i);
}

static void	ft_putposint(intmax_t n, Formatter *fr)
{
	if (n > 9)
		ft_putposint(n / 10, fr);
	ft_putchar('0' + (n % 10));
}

void		display_diu_signed(Formatter *fr, intmax_t i)
{
	if (i < 0)
		i *= -1;
	ft_putposint(i, fr);
}

int			resolver_diu2(uintmax_t *ui, Formatter *fr)
{
	if (!(ft_strcmp(fr->length, "hh")))
		(*ui) = (intmax_t)(va_arg(*(fr->ap), int));
	else if (!(ft_strcmp(fr->length, "h")))
		(*ui) = (intmax_t)(va_arg(*(fr->ap), int));
	else if (!(ft_strcmp(fr->length, "l")))
		(*ui) = (intmax_t)(va_arg(*(fr->ap), long));
	else if (!(ft_strcmp(fr->length, "ll")))
		(*ui) = (intmax_t)(va_arg(*(fr->ap), long long));
	else
		(*ui) = (intmax_t)(va_arg(*(fr->ap), int));
	return (field_width_resolver(fr, *ui));
}
