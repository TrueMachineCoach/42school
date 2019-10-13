/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:21:32 by gtapioca          #+#    #+#             */
/*   Updated: 2019/10/12 12:38:36 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		start_board_size(t_tetromino *begin_list)
{
	int			i;
	int			c;
	t_tetromino	*current;

	i = 0;
	c = 0;
	current = begin_list;
	while (current)
	{
		current = current->next;
		c++;
	}
	c *= 4;
	while (i * i < c)
		i++;
	return (i);
}

t_map	*new_map(int c, t_tetromino *begin_list)
{
	int		i;
	int		j;
	t_map	*new_map;

	i = 0;
	if (!(new_map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!(new_map->arr = (char **)malloc(sizeof(char *) * (c + 1))))
		memory_delete_error(new_map, begin_list);
	while (i < c)
	{
		j = 0;
		if (!((new_map->arr)[i] = (char *)malloc(sizeof(char) * (c + 1))))
			memory_delete_error(new_map, begin_list);
		while (j < c)
		{
			(new_map->arr)[i][j] = '.';
			j++;
		}
		(new_map->arr)[i][j] = '\0';
		i++;
		new_map->size = i;
	}
	new_map->size = c;
	return (new_map);
}

void	output_map(t_map **map, t_tetromino *begin_list)
{
	int	i;
	int j;

	if (!((*map) = new_map(start_board_size(begin_list), begin_list)))
		memory_delete_error(0, begin_list);
	fill_tetr(map, begin_list, 0, 0);
	i = 0;
	while (i < (*map)->size)
	{
		j = 0;
		while (((*map)->arr)[i][j])
		{
			write(1, &(((*map)->arr)[i][j]), 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	memory_deleter(begin_list, *map);
}

int		main(int argc, char **argv)
{
	t_map			*map;
	t_tetromino		*begin_list;
	int				fd;

	map = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		if (read_tetreminos(fd, &begin_list))
			output_map(&map, begin_list);
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "usage ./fillit source_file_path\n", 33);
	return (0);
}
