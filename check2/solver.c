/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:10:09 by bandrow           #+#    #+#             */
/*   Updated: 2019/10/13 12:46:14 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		compare_with_next(t_tetromino *c, t_tetromino *n)
{
	if (c->height == 4 && n->height == 4 && c->width == 1 && n->width == 1)
		return (1);
	if (c->height == 1 && n->height == 1 && c->width == 4 && n->width == 4)
		return (1);
	return (0);
}

int		check_fill(t_map *map, t_tetromino *tetr, int i, int k)
{
	int x;
	int y;
	int j;

	y = tetr->min->y;
	while (y < tetr->height + tetr->min->y)
	{
		j = k;
		x = tetr->min->x;
		while (x < tetr->width + tetr->min->x)
		{
			if ((tetr->tetr)[y][x] == '#' &&
				map->arr[i][j] != '.' && map->arr[i][j] != '\0')
				return (0);
			x++;
			j++;
		}
		i++;
		y++;
	}
	return (1);
}

int		fill_tetr_2(t_map *map, t_tetromino *tetr, int i, int k)
{
	int x;
	int y;
	int j;

	if (!check_fill(map, tetr, i, k))
		return (0);
	y = tetr->min->y;
	while (y < tetr->height + tetr->min->y)
	{
		x = tetr->min->x;
		j = k;
		while (x < tetr->width + tetr->min->x)
		{
			if ((tetr->tetr)[y][x++] == '#')
				(map->arr)[i][j] = (tetr->value);
			j++;
		}
		i++;
		y++;
	}
	return (1);
}

int		fill_tetr_dop(t_map **map, t_tetromino *c)
{
	(*map) = map_expander((*map));
	return (fill_tetr(map, c, 0, 0));
}

int		fill_tetr(t_map **map, t_tetromino *c, int i, int j)
{
	if (!c)
		return (1);
	while (i < (*map)->size - c->height + 1)
	{
		j = 0;
		while (j < (*map)->size - c->width + 1)
		{
			if (fill_tetr_2((*map), c, i, j))
			{
				if (fill_tetr(map, c->next, 0, 0))
					return (1);
				else
				{
					del_tetr_from_map((*map), c, i, j);
					if (compare_with_next(c, c->next) && c->value != 'A')
						return (0);
				}
			}
			j++;
		}
		i++;
	}
	if (c->value == 'A')
		return (fill_tetr_dop(map, c));
	return (0);
}
