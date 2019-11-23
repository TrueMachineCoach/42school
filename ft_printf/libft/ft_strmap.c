/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:55:09 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 17:09:34 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	str = 0;
	if (s)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s));
		if (str)
		{
			while (s[i])
			{
				str[i] = f(s[i]);
				i++;
			}
		}
	}
	return (str);
}
