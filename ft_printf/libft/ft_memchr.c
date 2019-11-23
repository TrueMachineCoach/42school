/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 09:34:13 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/17 10:34:46 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	let;
	size_t			i;

	i = 0;
	str = (unsigned char*)s;
	let = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == let)
			return (&str[i]);
		i++;
	}
	return (0);
}
