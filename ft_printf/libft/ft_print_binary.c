/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:22:18 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/17 11:26:46 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_binary(unsigned int num)
{
	if (num > 1)
		ft_print_binary(num / 2);
	ft_putchar((num % 2) + '0');
}
