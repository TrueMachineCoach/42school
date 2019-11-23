/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:46:55 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/17 15:32:40 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char *str)
{
	int in_word;
	int count_elem;

	count_elem = 0;
	if (str)
	{
		in_word = 0;
		while (*str)
		{
			if (ft_is_space(*str))
				in_word = 0;
			else if (!in_word)
			{
				count_elem++;
				in_word = 1;
			}
			str++;
		}
	}
	return (count_elem);
}
