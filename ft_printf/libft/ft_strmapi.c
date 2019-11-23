/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:05:38 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/16 11:50:17 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = 0;
	if (s)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s));
		if (str)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (str);
}
