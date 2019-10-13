/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_deleter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:10:09 by bandrow           #+#    #+#             */
/*   Updated: 2019/10/12 15:06:41 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	memory_delete_error(t_map *map, t_tetromino *tetr)
{
	memory_deleter(tetr, map);
	exit(0);
}

void	memory_deleter2(t_tetromino *current)
{
	int i;

	i = 0;
	while (i < 4 && (current->tetr)[i])
	{
		free((current->tetr)[i]);
		i++;
	}
	free(current->tetr);
	free(current->min);
}

void	memory_deleter(t_tetromino *begin_list, t_map *map)
{
	int			i;
	t_tetromino	*buff;

	i = 0;
	if (begin_list)
	{
		while (begin_list)
		{
			buff = begin_list;
			memory_deleter2(begin_list);
			begin_list = begin_list->next;
			free(buff);
		}
	}
	if (map)
	{
		while (i < map->size)
		{
			free((map->arr)[i]);
			i++;
		}
		free(map->arr);
		free(map);
	}
}
