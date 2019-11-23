/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 09:36:32 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 17:06:11 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	result = (char*)malloc((len + 1) * sizeof(char));
	if (result)
	{
		len = 0;
		while (s1[len])
		{
			result[len] = s1[len];
			len++;
		}
		result[len] = '\0';
	}
	return (result);
}
