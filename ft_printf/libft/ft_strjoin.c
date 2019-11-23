/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:29:40 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 17:39:42 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_str;

	str = 0;
	if (s1 && s2)
	{
		len_str = ft_strlen(s1) + ft_strlen(s2);
		str = ft_strnew(len_str);
		if (str)
		{
			ft_strcpy(str, s1);
			ft_strlcat(str, s2, len_str + 1);
		}
	}
	return (str);
}
