/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:58:08 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/09 18:09:21 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *result;

	result = 0;
	while (*s)
	{
		if (*s == c)
			result = (char*)s;
		s++;
	}
	if (!result && !c)
		result = (char*)s;
	return (result);
}
