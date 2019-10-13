/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:16:02 by gtapioca          #+#    #+#             */
/*   Updated: 2019/10/12 15:06:53 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct			s_map
{
	char				**arr;
	int					size;
}						t_map;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_tetromino
{
	char				**tetr;
	t_point				*min;
	int					width;
	int					height;
	char				value;
	struct s_tetromino	*next;
}						t_tetromino;

void					add_last(t_tetromino **begin_list, t_tetromino *new);
t_tetromino				*ft_new_tetrimino(char *str, char letter,
						t_tetromino *begin_list);
int						read_tetreminos(int fd, t_tetromino **begin_list);
void					memory_deleter(t_tetromino *begin_list, t_map *map);
t_point					*new_point(int xmin, int ymin);
void					is_validate_form(int index, char *tetr,
						int count, int *sides);
int						is_validate(char *tetr, int count);
char					*putchar_to_tetromino(int *c,
						char *str, int k, char **tetr);
void					put_min_height_width_helper(int *c);
void					put_min_height_width(t_tetromino *new_tert,
						t_tetromino *begin_list);
int						check_fill(t_map *map,
						t_tetromino *tetr, int i, int k);
int						fill_tetr_2(t_map *map,
						t_tetromino *tetr, int i, int k);
void					del_tetr_from_map(t_map *map,
						t_tetromino *tetr, int i, int j);
t_map					*map_expander(t_map *map);
int						fill_tetr(t_map **map, t_tetromino *c, int i, int j);
void					memory_deleter2(t_tetromino *current);
int						fill_tetr_helper(t_map *map, t_tetromino *current_tetr,
						int i, int j);
void					memory_delete_error(t_map *map, t_tetromino *tetr);

#endif
