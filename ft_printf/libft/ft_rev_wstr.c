/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:31:47 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 16:51:29 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print_word(char *str)
{
	while (!ft_is_space(*str) && *str)
	{
		ft_putchar(*str);
		str++;
	}
}

void			ft_rev_wstr(char *str)
{
	size_t	i;
	size_t	zero;
	int		count_word;

	if (str)
	{
		i = ft_strlen(str) - 1;
		count_word = 0;
		zero = 0;
		while (i >= zero)
		{
			while (i >= zero && ft_is_space(str[i]))
				i--;
			while (i >= zero && !ft_is_space(str[i]))
				i--;
			if (!ft_is_space(str[i + 1]))
			{
				if (count_word > 0)
					ft_putchar(' ');
				ft_print_word(&str[i + 1]);
				count_word++;
			}
		}
	}
}
