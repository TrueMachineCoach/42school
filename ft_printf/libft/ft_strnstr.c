/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:27:50 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 17:17:20 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	size_t	len_needle;
	char	*result;

	i = 0;
	len_needle = ft_strlen(needle);
	if (!needle[i])
		return ((char*)haystack);
	while (haystack[i] && i < (len - len_needle + 1))
	{
		j = i;
		tmp = 0;
		result = ((char*)&haystack[j]);
		while (haystack[j] == needle[tmp++] && j < len)
		{
			j++;
			if (!needle[tmp])
				return (result);
		}
		i++;
	}
	return (0);
}
