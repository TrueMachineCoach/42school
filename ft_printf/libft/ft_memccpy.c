/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 09:32:35 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/10 12:27:21 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	sym;
	unsigned char	*tmp;
	unsigned char	*area;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)src;
	area = (unsigned char*)dst;
	sym = (unsigned char)c;
	while (i < n)
	{
		if (tmp[i] == sym)
		{
			area[i] = tmp[i];
			return ((void*)(area + i + 1));
		}
		area[i] = tmp[i];
		i++;
	}
	return (0);
}
