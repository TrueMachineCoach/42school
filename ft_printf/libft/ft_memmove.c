/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 09:33:41 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 16:39:13 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*nsrc;
	char	*ndst;
	size_t	i;

	nsrc = (char*)src;
	ndst = (char*)dst;
	if (nsrc < ndst)
	{
		i = 1;
		while (i <= len)
		{
			ndst[len - i] = nsrc[len - i];
			i++;
		}
	}
	else if (nsrc > ndst)
	{
		i = 0;
		while (i < len)
		{
			ndst[i] = nsrc[i];
			i++;
		}
	}
	return (dst);
}
