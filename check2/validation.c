/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:21:32 by gtapioca          #+#    #+#             */
/*   Updated: 2019/10/13 12:36:05 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	*putchar_to_tetromino(int *c, char *str, int k, char **tetr)
{
	tetr[c[0]][c[1]] = *str;
	if (k == 1)
		c[1]++;
	else
		c[0]++;
	str++;
	return (str);
}

t_point	*new_point(int xmin, int ymin)
{
	t_point *new;

	if (!(new = (t_point *)malloc(sizeof(t_point))))
		return (0);
	new->x = xmin;
	new->y = ymin;
	return (new);
}

void	is_validate_form(int index, char *tetr, int count, int *sides)
{
	if (index + 1 <= count && tetr[index + 1] == '#')
		(*sides) += 2;
	if (index - 5 >= 0 && tetr[index - 5] == '#')
		(*sides) += 2;
}

int		is_validate(char *tetr, int count)
{
	int i;
	int sides;
	int blocks;

	i = 0;
	blocks = 0;
	sides = 0;
	if (count < 20 || (count == 20 && tetr[count - 1] != '\n'))
		return (0);
	while (i < 20)
	{
		if ((i + 1) % 5 != 0 && tetr[i] != '#' && tetr[i] != '.')
			return (0);
		if (((i + 1) % 5 == 0 && tetr[i] != '\n') ||
				(tetr[i] == '#' && blocks++ > 4))
			return (0);
		if (tetr[i] == '#')
			is_validate_form(i, tetr, count, &sides);
		i++;
	}
	if (count == 21 && tetr[count - 1] != '\n')
		return (0);
	if (blocks != 4 || i < 19)
		return (0);
	return (sides == 6 || sides == 8);
}
