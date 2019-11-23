/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inf_nan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:41:01 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:49:04 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	put_multiply_2x5_array(int *mass, int *u, int *i)
{
	(*i) = 0;
	if ((*u) >= 0)
		while ((*i) < (*u))
		{
			intmass_multiply(mass, 2);
			(*i)++;
		}
	else
		while ((*i) < (-1 * (*u)))
		{
			intmass_multiply(mass, 5);
			(*i)++;
		}
}

void	put_zero_to_array(int *mass, int *i)
{
	(*i) = 0;
	while ((*i) < 16500)
	{
		mass[(*i)] = 0;
		(*i)++;
	}
}

void	finder_not_zero(int *mass, int *i)
{
	(*i) = 16499;
	while (mass[(*i)] == 0)
		(*i)--;
}

int		print_nan_inf_dop(Formatter *fr, int *k, int *i, size_t *print_helper)
{
	size_t tmp;
	int c;

	if (fr->flags[1] == '+' && (*k) == 1)
		write(1, "+", 1);
	(*i) = (*i) - (*print_helper);
	c = print_inf_nan_1(k);
	tmp = 0;
	print_inf_nan_2(i, &tmp);
}

int		print_nan_inf(Formatter *fr, int k)
{
	size_t		print_helper;
	int			i;
	int			j;

	i = fr->width;
	if (k < 0 || fr->flags[1] == '+')
		print_helper = 4;
	else
		print_helper = 3;
	if (fr->flags[0] == '-' && fr->width > print_helper)
		return (print_nan_inf_dop(fr, &k, &i, &print_helper));
	else if (fr->width > print_helper)
	{
		j = print_inf_nan_2(&i, &print_helper);
		if (fr->flags[1] == '+' && k == 1)
			write(1, "+", 1);
		return (print_inf_nan_1(&k) + j);
	}
	else
	{
		if (fr->flags[1] == '+' && k == 1)
			write(1, "+", 1);
		return (print_inf_nan_1(&k));
	}
}
