/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:21:43 by gtapioca          #+#    #+#             */
/*   Updated: 2019/10/12 15:35:53 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void		add_last(t_tetromino **begin_list, t_tetromino *new)
{
	t_tetromino *current;

	current = *begin_list;
	if (!(current))
	{
		*begin_list = new;
		(*begin_list)->next = 0;
	}
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void		put_min_height_width_helper(int *c)
{
	if (c[1] < c[2])
		c[2] = c[1];
	if (c[0] < c[3])
		c[3] = c[0];
	if (c[1] > c[4])
		c[4] = c[1];
	if (c[0] > c[5])
		c[5] = c[0];
}

void		put_min_height_width(t_tetromino *new_tert, t_tetromino *begin_list)
{
	int c[6];

	c[0] = 0;
	c[1] = 0;
	c[2] = 3;
	c[3] = 3;
	c[4] = 0;
	c[5] = 0;
	while ((new_tert->tetr)[c[0]])
	{
		c[1] = 0;
		while (c[1] < 4)
		{
			if ((new_tert->tetr)[c[0]][c[1]] == '#')
				put_min_height_width_helper(c);
			++c[1];
		}
		c[0]++;
	}
	new_tert->height = c[5] - c[3] + 1;
	new_tert->width = c[4] - c[2] + 1;
	if (!(new_tert->min = new_point(c[2], c[3])))
		memory_delete_error(0, begin_list);
}

t_tetromino	*ft_new_tetrimino(char *str, char letter, t_tetromino *begin_list)
{
	int			c[2];
	t_tetromino *new_tetromino;

	c[0] = 0;
	if (!(new_tetromino = (t_tetromino *)malloc(sizeof(t_tetromino))))
		return (0);
	if (!(new_tetromino->tetr = (char **)malloc(sizeof(char *) * 5)))
		return (0);
	while (c[0] < 4)
	{
		c[1] = 0;
		if (!((new_tetromino->tetr)[c[0]] = (char *)malloc(sizeof(char) * 5)))
			return (0);
		while (c[1] < 4)
			str = putchar_to_tetromino(c, str, 1, new_tetromino->tetr);
		str = putchar_to_tetromino(c, str, 0, new_tetromino->tetr);
	}
	(new_tetromino->tetr)[c[0]] = 0;
	put_min_height_width(new_tetromino, begin_list);
	new_tetromino->value = letter;
	new_tetromino->next = 0;
	return (new_tetromino);
}

int			read_tetreminos(int fd, t_tetromino **new_tetr)
{
	char		buff[22];
	int			ret;
	t_tetromino *curr;
	char		letter;

	if (fd < 0)
		return (0);
	letter = 'A';
	while ((ret = read(fd, buff, 21)))
	{
		buff[ret] = '\0';
		if (!(is_validate(buff, ret)))
			return (0);
		if (!(curr = ft_new_tetrimino(buff, letter, *new_tetr)))
			memory_delete_error(0, *new_tetr);
		add_last(new_tetr, curr);
		letter++;
	}
	if (((0 < ret) && (ret < 19)) || (ret == 0 && !(*new_tetr)) ||
		buff[20] == '\n')
		return (0);
	return (1);
}
