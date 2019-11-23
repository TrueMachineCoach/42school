/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:47:24 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>

void	rounder_double(int *mass, uintmax_t precision, uintmax_t delimiter)
{
	int			reminder;
	uintmax_t	i;

	i = delimiter - precision - 1;
	reminder = 0;
	if (precision <= delimiter)
	{
		while (i < delimiter - precision && i < 16500)
		{
			if (mass[i] == 10)
				mass[i + 1] += 1;
			if (mass[i] >= 5 && mass[i] < 10)
				mass[i + 1] += 1;
			i++;
		}
		while (mass[i] == 10 && i < 16500)
		{
			mass[i] = 0;
			mass[i + 1] += 1;
			i++;
		}
	}
}

void	display_long_double_eE2(int *mass, long double *num, int *u)
{
	int					i;
	union long_double	f;

	i = 0;
	f.f = *num;
	while (i < 16500)
		mass[i++] = 0;
	(*u) = f.bin.exp - 16383 - 63;
	put_in_intmass(mass, f.bin.frac);
	i = 0;
	if ((*u) >= 0)
		while (i < (*u))
		{
			intmass_multiply(mass, 2);
			i++;
		}
	else
		while (i < (-1 * (*u)))
		{
			intmass_multiply(mass, 5);
			i++;
		}
}

void print_zero_e(Formatter *fr)
{
	int j;

	j = 0;
	if (fr->precision == 0 && fr->flags[3] != '#')
		write(1, "0", 1);
	else
		write(1, "0.", 2);
	while (j < fr->precision)
	{
		write(1, "0", 1);
		j++;
	}
}

void	display_long_double_eE3(uintmax_t *pr, int *i, Formatter *fr, int *mass)
{
	int			count;
	uintmax_t	help;

	help = 0;
	count = 0;
	while ((*i) >= 0 && (help == 0 || help < (*pr)))
	{
		if (count == 1 && (*pr) != 0)
			write(1, ".", 1);
		if (count >= 1 || ((*pr) == 0))
			help++;
		mass[(*i)] = mass[(*i)] + '0';
		write(1, &mass[(*i)], 1);
		if ((*pr) == 0 && fr->flags[3] == '#')
			write(1, ".", 1);
		(*i)--;
		count++;
	}
	if (*i == -6 || *i == -7)
	{
		print_zero_e(fr);
		count = -1;
	}
	while (help < (*pr) && count != -1)
		write(1, "0", 1) && help++;
	if (fr->specifier == 'E' || fr->specifier == 'G')
		write(1, "E", 1);
	if (fr->specifier == 'e' || fr->specifier == 'g')
		write(1, "e", 1);
}

void	display_long_double_eE4(long double *num, uintmax_t *number_length)
{
	if ((*num) < 1 && (*num) > -1 && *num != 0)
		write(1, "-", 1);
	else
		write(1, "+", 1);
	if ((*number_length) < 10)
		write(1, "0", 1);
}

void	display_long_double_eE(long double num, uintmax_t precision,
										Formatter *fr, uintmax_t number_length)
{
	int mass[16500];
	int i;
	int u;

	display_long_double_eE2(mass, &num, &u);
	i = 16499;
	if (num > -1 && num < 1)
	{
		while (mass[i] == 0)
			i--;
		rounder_double(mass, precision, i);
		i = 16499;
		while (mass[i] == 0)
			i--;
	}
	else
	{
		while (mass[i] == 0 && i > (-1 * u))
			i--;
		rounder_double(mass, precision, i);
	}
	display_long_double_eE3(&precision, &i, fr, mass);
	display_long_double_eE4(&num, &number_length);
	display_diu_unsigned(number_length);
}

void	put_in_intmass(int *dest, uintmax_t src)
{
	while (src / 10)
	{
		*dest = src % 10;
		dest++;
		src = src / 10;
	}
	*dest = src % 10;
}

void	intmass_multiply(int *test, int k)
{
	int i;
	int reminder;

	i = 0;
	reminder = 0;
	while (i < 16500)
	{
		test[i] = test[i] * k + reminder;
		if (test[i] > 9)
		{
			reminder = test[i] / 10;
			test[i] = test[i] % 10;
		}
		else
			reminder = 0;
		i++;
	}
}

void	intmass_plus(int *test, int *test2)
{
	int i;
	int reminder;

	i = 0;
	reminder = 0;
	while (i < 16500)
	{
		test[i] = test[i] + test2[i] + reminder;
		if (test[i] > 9)
		{
			reminder = test[i] / 10;
			test[i] = test[i] % 10;
		}
		else
			reminder = 0;
		i++;
	}
}

void	put_in_intmass_double(int *help, int *dest, uintmax_t src)
{
	put_in_intmass(dest, src);
	put_in_intmass(help, 2251799813685248 * 2);
	intmass_plus(dest, help);
}

void	display_long_double3(int *i, int *mass, long double *num, int *u)
{
	union long_double f;

	f.f = (*num);
	while ((*i) < 16500)
	{
		mass[(*i)] = 0;
		(*i)++;
	}
	(*u) = f.bin.exp - 16383 - 63;
	put_in_intmass(mass, f.bin.frac);
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

void	display_long_double4(int *u, uintmax_t *help, uintmax_t *precision)
{
	if ((*u) >= 0)
		write(1, ".", 1);
	while ((*help) < (*precision))
	{
		write(1, "0", 1);
		(*help)++;
	}
}

int		display_long_double2(int *u, int *mass, uintmax_t *pr, long double *num)
{
	int	i;

	i = 0;
	display_long_double3(&i, mass, num, u);
	if ((*u) < 0)
		rounder_double(mass, (*pr), (-1 * (*u)));
	i = 16499;
	if ((*num) < 1 && (*num) > -1)
		i = -1 * (*u);
	else
		while (mass[i] == 0)
			i--;
	return (i);
}

void		display_long_double(long double num, uintmax_t precision, Formatter *fr)
{
	int			mass[16500];
	int			i;
	int			u;
	uintmax_t	help;

	i = display_long_double2(&u, mass, &precision, &num);
	help = 0;
	while (i >= 0 && ((help == 0) || (help < precision)))
	{
		if (i == ((-1 * u) - 1) && help < precision)
			write(1, ".", 1);
		if (precision == 0)
		{
			if (i <= ((-1 * u)))
				help++;
		}
		else if (i < ((-1 * u)))
			help++;
		mass[i] = mass[i] + '0';
		write(1, &mass[i], 1);
		if (i == (-1 * u) && fr->flags[3] == '#' && precision == 0)
			write(1, ".", 1);
		i--;
	}
	display_long_double4(&u, &help, &precision);
}

void	display_double2(int *help, int *mass, double *num, int *u)
{
	union double_double	f;
	int					i;

	f.f = *num;
	i = 0;
	while (i < 16500)
	{
		mass[i] = 0;
		help[i++] = 0;
	}
	(*u) = f.bin.exp - 1023 - 52;
	put_in_intmass_double(help, mass, f.bin.frac);
	i = 0;
	if ((*u) >= 0)
		while (i < (*u))
		{
			intmass_multiply(mass, 2);
			i++;
		}
	else
		while (i < (-1 * (*u)))
		{
			intmass_multiply(mass, 5);
			i++;
		}
}

int		display_double3(int *mass, uintmax_t *precision, double *num, int *u)
{
	int i;

	i = 0;
	if ((*u) < 0)
		rounder_double(mass, (*precision), (-1 * (*u)));
	i = 16499;
	if ((*num) < 1 && (*num) > -1)
		i = -1 * (*u);
	else
		while (mass[i] == 0)
			i--;
	return (i);
}

void	display_double5(int *u, uintmax_t *help1, uintmax_t *precision)
{
	if ((*u) >= 0)
		write(1, ".", 1);
	while ((*help1) < (*precision))
	{
		write(1, "0", 1);
		(*help1)++;
	}
}

void	display_double4(int *i, uintmax_t *help1, uintmax_t *precision, int *u)
{
	if ((*i) == ((-1 * (*u)) - 1) && (*help1) < (*precision))
		write(1, ".", 1);
	if ((*precision) == 0)
	{
		if ((*i) <= ((-1 * (*u))))
			(*help1)++;
	}
	else if ((*i) < ((-1 * (*u))))
		(*help1)++;
}

void	display_double(double num, uintmax_t precision, Formatter *fr)
{
	int			mass[16500];
	int			help[16500];
	int			i;
	int			u;
	uintmax_t	help1;

	display_double2(help, mass, &num, &u);
	i = display_double3(mass, &precision, &num, &u);
	help1 = 0;
	while (i >= 0 && ((help1 == 0) || (help1 < precision)))
	{
		display_double4(&i, &help1, &precision, &u);
		mass[i] = mass[i] + '0';
		write(1, &mass[i], 1);
		if (i == (-1 * u) && fr->flags[3] == '#' && precision == 0)
			write(1, ".", 1);
		i--;
	}
	display_double5(&u, &help1, &precision);
}
