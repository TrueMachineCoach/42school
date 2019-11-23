/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:44:10 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 17:24:07 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	tmp;
	char	*result;

	i = 0;
	if (!needle[i])
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		tmp = i;
		result = (char*)(haystack + i);
		while (haystack[tmp] && needle[j] == haystack[tmp++])
			j++;
		if (!needle[j])
			return (result);
		i++;
	}
	return (0);
}
