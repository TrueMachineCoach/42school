/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_11.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/22 16:09:59 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int		reculc_help_helper(Formatter *fr, int reculc_help)
{
	if (reculc_help == 0 && fr->flags[3] == '#' && fr->precision >= 1)
		return (fr->precision - 1);
	if (reculc_help == 0 && fr->flags[3] == '#' && fr->precision == 0)
		return (0);
	if (reculc_help == 0 && fr->flags[3] == '#' && fr->precision == -1)
		return (-1);
	return (reculc_help);
}
