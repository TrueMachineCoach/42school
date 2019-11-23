/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:18:47 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/14 14:20:39 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_s1;
	size_t len_s2;
	size_t i;
	size_t j;

	len_s1 = ft_strlen(dst);
	len_s2 = ft_strlen(src);
	i = len_s1;
	j = 0;
	if (size < len_s1 + 1)
		return (len_s2 + size);
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len_s2 + len_s1);
}
