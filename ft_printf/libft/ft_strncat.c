/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:11:01 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 17:15:31 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = 0;
	while (len_s2 < n && s2[len_s2])
	{
		s1[len_s1] = s2[len_s2];
		len_s1++;
		len_s2++;
	}
	s1[len_s1] = '\0';
	return (s1);
}
