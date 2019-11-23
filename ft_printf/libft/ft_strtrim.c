/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:40:00 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 17:25:31 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t i_start;
	size_t i_end;

	if (s)
	{
		i_start = 0;
		while (isspace(s[i_start]))
			i_start++;
		if (s[i_start] == '\0')
			return (ft_strnew(0));
		i_end = ft_strlen(s) - 1;
		while (isspace(s[i_end]))
			i_end--;
		return (ft_strsub(s, i_start, i_end - i_start + 1));
	}
	return (0);
}
