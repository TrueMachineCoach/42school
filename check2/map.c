/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:07:18 by bandrow           #+#    #+#             */
/*   Updated: 2019/10/12 15:11:38 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	del_tetr_from_map(t_map *map, t_tetromino *tetr, int i, int j)
{
	int i_active;
	int j_active;

	i_active = i;
	while (i_active < map->size)
	{
		j_active = j;
		while (j_active < map->size)
		{
			if ((map->arr)[i_active][j_active] == tetr->value)
				(map->arr)[i_active][j_active] = '.';
			j_active++;
		}
		i_active++;
	}
}

t_map	*map_expander(t_map *map)
{
	int i;
	int j;
	int k;

	i = 0;
	k = map->size + 1;
	while (i < map->size)
		free((map->arr)[i++]);
	i = 0;
	free(map->arr);
	if (!(map->arr = (char **)malloc(sizeof(char *) * (k + 1))))
		memory_delete_error(map, 0);
	while (i < k)
	{
		j = 0;
		if (!((map->arr)[i] = (char *)malloc(sizeof(char ) * (k + 1))))
			memory_delete_error(map, 0);
		while (j < k)
			(map->arr)[i][j++] = '.';
		(map->arr)[i][j] = '\0';
		i++;
	}
	map->size = k;
	return (map);
}
