/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_formatt_resolver_copy.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 14:15:38 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

// uintmax_t digit_counter_e_2(long double num, Formatter *fr)
// {
//     int mass[16500];
//     intmax_t i;
//     int u;
//     union long_double f;

//     f.f = num;
// 	put_zero_to_array();
// 	u = f.bin.exp - 16383 - 63;
//     put_in_intmass(mass, f.bin.frac);
// 	put_multiply_2x5_array(mass, u);
//     i = 16499;
// 	if (num > -1 && num < 1)
// 	{
// 		finder_not_zero();
// 		rounder_double(mass, fr->precision, i);
// 		finder_not_zero();
// 	}
// 	else
// 		while (mass[i] == 0 && i > (-1 * u)) 
// 			i--;
// 	if (u < 0)
// 		return(i - (-1 * u));
//    	return (i);
// }

// uintmax_t returner_e_1(long double num, intmax_t i, int u)
// {
// 	if (num > -1 && num < 1)
// 		return ((-1 * u) - i);
// 	if (u < 0)
// 		return(i - (-1 * u));
//    	return (i);
// }

// uintmax_t digit_counter_e_1(long double num, Formatter *fr)
// {
//     int mass[16500];
//     intmax_t i;
//     int u;
//     union long_double f;

//     f.f = num;
//     i = 0;
// 	put_zero_to_array();
// 	u = f.bin.exp - 16383 - 63;
//     put_in_intmass(mass, f.bin.frac);
// 	put_multiply_2x5_array(mass, u);
//     i = 16499;
// 	if (num > -1 && num < 1)
// 	{
// 		finder_not_zero();
// 		rounder_double(mass, fr->precision, i);
// 		finder_not_zero();
// 	}
// 	else
// 		while (mass[i] == 0 && i > (-1 * u)) 
// 			i--;
//    	return (returner_e_1(num, i, u));
// }

// uintmax_t digit_counter_e(long double num, Formatter *fr)
// {
//     intmax_t i;
//     int u;
   
// 	u = 0;
// 	i = digit_counter_e_1(num, fr);
// 	while (i / 10)
// 	{
// 		i = i / 10;
// 		u++;
// 	}
// 	u++;
//     return (u);
// }

// uintmax_t digit_counter_long_double(long double num, uintmax_t precision, Formatter *fr)
// {
//     int mass[16500];
//     int i;
//     int u;
//     union long_double f;

//     f.f = num;
//     i = 0;
// 	put_zero_to_array(mass, &i);
// 	u = f.bin.exp - 16383 - 63;
//     put_in_intmass(mass, f.bin.frac);
// 	put_multiply_2x5_array(mass, &u, &i);
//     i = 16499;
// 	while (mass[i] == 0 && i > (-1 * u))
// 		i--;
//     if (u < 0)
//         return (i - ((-1) * u) + precision + 1);
//     else if (fr->flags[3] == '#' && precision == 0)
//         return (i + 2);
// 	else
//         return (i + 1 + precision);
// }
//     f.f = num;
//     i = 0;
// 	put_zero_to_array(mass, &i);
// 	u = f.bin.exp - 16383 - 63;
//     put_in_intmass(mass, f.bin.frac);
// 	put_multiply_2x5_array(mass, &u, &i);
//     i = 16499;
// 	while (mass[i] == 0 && i > (-1 * u))
// 		i--;
//     if (u < 0)
//         return (i - ((-1) * u) + precision + 1);
//     else if (fr->flags[3] == '#' && precision == 0)
//         return (i + 2);
// 	else
//         return (i + 1 + precision);
// }

// uintmax_t number_lenght_fact_definer_signed(Formatter *fr, int number_length, intmax_t i)
// {
// 	uintmax_t number_lenght_fact;

// 	if (fr->precision > number_length)
// 	{
// 		if (fr->flags[1] == '+' || i < 0)
// 			number_lenght_fact = fr->precision + 1;
// 		else
// 			number_lenght_fact = fr->precision;
// 	}
// 	else
// 	{
// 		if (fr->flags[1] == '+' || i < 0)
// 			number_lenght_fact = number_length + 1;
// 		else
// 			number_lenght_fact = number_length;
// 	}
// 	return(number_lenght_fact);
// }

// uintmax_t number_lenght_fact_definer_unsigned(Formatter *fr, int number_length)
// {
// 	uintmax_t number_lenght_fact;

// 	if (fr->precision > number_length)
// 	{
// 		if (fr->flags[1] == '+')
// 			number_lenght_fact = fr->precision + 1;
// 		else
// 			number_lenght_fact = fr->precision;
// 	}
// 	else
// 	{
// 		if (fr->flags[1] == '+')
// 			number_lenght_fact = number_length + 1;
// 		else
// 			number_lenght_fact = number_length;
// 	}
// 	return(number_lenght_fact);
// }

// int number_length_counter_unsigned(uintmax_t i, int base)
// {
// 	int			number_length;
// 	uintmax_t	k;

// 	k = i;
// 	number_length = 0;
// 	while(k / base > 0)
// 	{
// 		k = k / base;
// 		number_length++;
// 	}
// 	number_length++;
// 	return(number_length);
// }

// void print_left_alignment_help(Formatter *fr, int number_length, intmax_t i, int c)
// {
// 	c += number_length;
// 	while(c < fr->width)
// 	{
// 		write(1, " ", 1);
// 		c++;
// 	}
// }

// void print_signed_left_alignment(Formatter *fr, int number_length, intmax_t i)
// {
// 	int count_prec;
// 	int c;
	
// 	c = 0;
// 	if (i > 0 && fr->flags[1] == '+')
// 	{
// 		write(1, "+", 1);
// 		c++;
// 	}
// 	if (i < 0)
// 	{
// 		write(1, "-", 1);
// 		c++;
// 	}
// 	count_prec = 0;
// 	while (count_prec < fr->precision - number_length)
// 	{
// 		write(1, "0", 1);
// 		c++;
// 		count_prec++;
// 	}
// 	display_diu_signed(fr, i);
// 	print_left_alignment_help(fr, number_length, i, c);
// }

// void print_unsigned_left_alignment(Formatter *fr, int number_length, uintmax_t i)
// {
// 	int count_prec;
// 	int c;
	
// 	c = 0;
// 	if (fr->flags[1] == '+')
// 	{
// 		write(1, "+", 1);
// 		c++;
// 	}
// 	count_prec = 0;
// 	while (count_prec < fr->precision - number_length)
// 	{
// 		write(1, "0", 1);
// 		c++;
// 		count_prec++;
// 	}
// 	display_diu_unsigned(i);
// 	c += number_length;
// 	while(c < fr->width)
// 	{
// 		write(1, " ", 1);
// 		c++;
// 	}
// }

// void print_unsigned_positive_precision(Formatter *fr, int number_length, uintmax_t i)
// {
// 	int c;

// 	c = 0;
// 	if (fr->precision > number_length)
// 		while (c < fr->width - fr->precision)
// 		{
// 			write(1, " ", 1);
// 			c++;
// 		}
// 	else
// 		while (c < (int)fr->width - number_length)
// 		{
// 			write(1, " ", 1);
// 			c++;
// 		}
// 	while (c < (int)fr->width - number_length)
// 	{
// 		write(1, "0", 1);
// 		c++;
// 	}
// 	display_diu_unsigned(i);
// }

// void	print_last(Formatter *fr, uintmax_t number_length, uintmax_t i, int indic)
// {
// 	int c;

// 	c = 0;
// 	if (indic == 0)
// 		while (c <= (int)fr->width - (int)number_length - 1)
// 		{
// 			if (fr->flags[4] == '0')
// 				write(1, "0", 1);
// 			else
// 				write(1, " ", 1);
// 			c++;
// 		}
// 	else
// 		while (c < fr->precision - (int)number_length)
// 		{
// 			write(1, "0", 1);
// 			c++;
// 		}
// 	display_diu_unsigned(i);
// }

// void field_width_resolver_unsigned(Formatter *fr, uintmax_t i)
// {
// 	int count_prec;
// 	int number_length;
// 	uintmax_t number_lenght_fact;

// 	number_length = number_length_counter_unsigned(i, 10);
// 	number_lenght_fact = number_lenght_fact_definer_unsigned(fr, number_length);
// 	if ((int)fr->width > (int)number_lenght_fact)
// 	{
// 		if (fr->flags[0] == '-')
// 			print_unsigned_left_alignment(fr, number_length, i);
// 		else
// 		{
// 			if (fr->precision >= 0)
// 				print_unsigned_positive_precision(fr, number_length, i);
// 			else
// 				print_last(fr, number_lenght_fact, i, 0);
// 		}
// 	}
// 	else
// 		print_last(fr, number_length, i, 1);
// }

// void print_positive_presision_signed_helper(Formatter *fr, intmax_t i, int c, int number_length)
// {
// 	if (i < 0)
// 	{
// 		write(1, "-", 1);
// 		c++;
// 	}
// 	else if (fr->flags[1] == '+' && i > 0)
// 	{
// 		write(1, "+", 1);
// 		c++;
// 	}
// 	else
// 	{
// 		write(1, " ", 1);
// 		c++;
// 	}	
// 	while (c < (int)fr->width - number_length)
// 	{
// 		write(1, "0", 1);
// 		c++;
// 	}
// 	display_diu_signed(fr, i);
// }

// void print_positive_precision_signed(Formatter *fr, intmax_t i, int number_length)
// {
// 	int c;

// 	c = 0;
// 	if (fr->precision > number_length)
// 		while (c < (int)fr->width - (int)fr->precision - 1)
// 		{
// 			write(1, " ", 1);
// 			c++;
// 		}
// 	else
// 		while (c < (int)fr->width - (int)number_length - 1)
// 		{
// 			write(1, " ", 1);
// 			c++;
// 		}
// 	print_positive_presision_signed_helper(fr, i, c, number_length);
// }

// void print_sign(Formatter *fr, uintmax_t number_lenght_fact, intmax_t i, int number_length)
// {
// 	int c;

// 	c = 0;
// 	if (i < 0 && fr->flags[4] == '0')
// 		write(1, "-", 1);
// 	if (fr->flags[1] == '+' && i > 0 && fr->flags[4] == '0')
// 		write(1, "+", 1);
// 	while (c <= (int)fr->width - (int)number_lenght_fact - 1)
// 	{
// 		if (fr->flags[4] == '0')
// 			write(1, "0", 1);
// 		else
// 			write(1, " ", 1);
// 		c++;
// 	}
// 	if (i < 0)
// 		write(1, "-", 1 && fr->flags[4] != '0');
// 	if (fr->flags[1] == '+' && i > 0 && fr->flags[4] != '0')
// 		write(1, "+", 1);
// }

// void print_zero_precision_signed(Formatter *fr, uintmax_t number_lenght_fact, intmax_t i, int number_length)
// {
// 	int c;

// 	c = 0;
// 	if (fr->width > number_lenght_fact)
// 		print_sign(fr, number_lenght_fact, i);
// 	else
// 	{
// 		if (fr->flags[1] == '+' && i > 0)
// 			write(1, "+", 1);
// 		if (i < 0)
// 			write(1, "-", 1);
// 		while (c < fr->precision - number_length)
// 		{
// 			write(1, "0", 1);
// 			c++;
// 		}
// 	}
// 	display_diu_signed(fr, i);
// }

// void field_width_resolver(Formatter *fr, intmax_t i)
// {
// 	int number_length;
// 	uintmax_t number_lenght_fact;

// 	number_length = number_length_counter_unsigned((i < 0 ? i * -1 : i), 10);
// 	number_lenght_fact = number_lenght_fact_definer_signed(fr, number_length, i);
// 	if (fr->width > number_lenght_fact)
// 	{
// 		if (fr->flags[0] == '-')
// 			print_signed_left_alignment(fr, number_length, i);
// 		else
// 		{
// 			if (fr->precision >= 0)
// 				print_positive_precision_signed(fr, i, number_length);
// 			else
// 				print_zero_precision_signed(fr, number_lenght_fact, i, number_length);
// 		}
// 	}
// 	else
// 		print_zero_precision_signed(fr, number_lenght_fact, i, number_length);
// }

// uintmax_t number_lenght_fact_ox(Formatter *fr, int number_length, uintmax_t i)
// {
// 	uintmax_t number_lenght_fact;

// 	if (fr->precision > number_length)
// 	{
// 		number_lenght_fact = fr->precision;
// 		if (fr->flags[3] == '#' && fr->specifier == 'o')
// 			number_lenght_fact++;
// 		if (fr->flags[3] == '#' && (fr->specifier == 'x' || fr->specifier == 'X'))
// 			number_lenght_fact += 2;
// 	}
// 	else
// 	{
// 		number_lenght_fact = number_length;
// 		if (fr->flags[3] == '#' && fr->specifier == 'o')
// 			number_lenght_fact++;
// 		if (fr->flags[3] == '#' && (fr->specifier == 'x' || fr->specifier == 'X'))
// 			number_lenght_fact += 2;
// 	}
// 	return (number_lenght_fact);
// }

// int hash_detector_ox(Formatter *fr, int c)
// {
// 	if (fr->flags[3] == '#' && fr->specifier == 'o')
// 	{
// 		write(1, "0", 1);
// 		if (fr->width > number_lenght_fact)
// 			c++;
// 	}
// 	if (fr->flags[3] == '#' && fr->specifier == 'x')
// 	{
// 		write(1, "0x", 2);
// 		if (fr->width > number_lenght_fact)
// 			c += 2;
// 	}
// 	if (fr->flags[3] == '#' && fr->specifier == 'X')
// 	{
// 		write(1, "0X", 2);
// 		if (fr->width > number_lenght_fact)
// 			c += 2;
// 	}
// 	return (c);
// }

// void print_left_alignment_ox(Formatter *fr, uintmax_t i, int number_length, uintmax_t number_lenght_fact)
// {
// 	int count_prec;
// 	int c;

// 	c = 0;
// 	count_prec = 0;
// 	c = hash_detector_ox(fr, c);
// 	while (count_prec < fr->precision - number_length)
// 	{
// 		write(1, "0", 1);
// 		c++;
// 		count_prec++;
// 	}
// 	handle_data(fr, i);
// 	c += number_length;
// 	while(c < fr->width)
// 	{
// 		write(1, " ", 1);
// 		c++;
// 	}			
// }

// void print_not_zero_p_ox(Formatter *fr, int number_length, uintmax_t number_lenght_fact, uintmax_t i)
// {
// 	int c;

// 	c = 0;
// 	if (fr->precision >= 0 && fr->width > number_lenght_fact)
// 		while (c < (int)fr->width - (int)number_lenght_fact)
// 		{
// 			write(1, " ", 1);
// 			c++;
// 		}
// 	if (fr->precision < 0 && fr->width > number_lenght_fact)
// 		while (c < (int)fr->width - (int)number_lenght_fact && fr->flags[4] != '0')
// 		{
// 			write(1, " ", 1);
// 			c++;
// 		}
// 	c = hash_detector_ox(fr, c);
// 	while (c < (int)fr->width - number_length)
// 	{
// 		write(1, "0", 1);
// 		c++;
// 	}
// 	handle_data(fr, i);
// }

// void field_width_resolver_ox(Formatter *fr, uintmax_t i)
// {
// 	int base;
// 	int number_length;
// 	uintmax_t number_lenght_fact;

//     if (fr->specifier == 'o')
//         base = 8;
//     else
//         base = 16;
// 	number_length = number_length_counter_unsigned(i, base);
// 	number_lenght_fact = number_lenght_fact_ox(fr, number_length);
	
// 	if (fr->width > number_lenght_fact)
// 	{
// 		if (fr->flags[0] == '-')
// 			print_left_alignment_ox(fr, i, number_length);			
// 		else
// 		{
// 			if (fr->precision >= 0)
// 				print_not_zero_p_ox(fr, number_length, number_lenght_fact, i);
// 			else
// 				print_not_zero_p_ox(fr, number_length, number_lenght_fact, i);
// 		}
// 	}
// 	else
// 		print_not_zero_p_ox(fr, number_length, number_lenght_fact, i);
// }

// uintmax_t number_length_fact_double(Formatter *fr, long double i, uintmax_t number_length)
// {
// 	uintmax_t number_lenght_fact;

// 	number_lenght_fact = number_length;
// 	if (fr->flags[1] == '+' || i < 0)
// 		number_lenght_fact += 1;
// 	if (fr->flags[3] == '#' && fr->precision == 0)
// 		number_lenght_fact += 1;
// 	if (fr->flags[3] != '#' && fr->precision == 0)
// 		number_length -= 1;
// 	if (fr->precision > 0)
// 		number_lenght_fact += 1;
// 	return (number_lenght_fact);
// }

// void print_left_alignment_long_double(Formatter *fr, long double i, uintmax_t number_length)
// {
// 	int c;

// 	c = 0;
// 	if (i > 0 && fr->flags[1] == '+')
// 	{
// 		write(1, "+", 1);
// 		c++;
// 	}
// 	if (i < 0)
// 	{
// 		write(1, "-", 1);
// 		c++;
// 	}
// 	display_long_double(i, fr->precision, fr);
// 	c += number_length;
// 	while(c < fr->width - 1)
// 	{
// 		write(1, " ", 1);
// 		c++;
// 	}			
// }

// void print_long_double_1(Formatter *fr, long double i)
// {
// 	if (fr->flags[1] == '+' && i > 0)
// 		write(1, "+", 1);
// 	if (i < 0)
// 		write(1, "-", 1);
// 	display_long_double(i, fr->precision, fr);
// }

// void print_long_double_1_1(Formatter *fr, int c, uintmax_t number_length)
// {
// 	while (c < (int)fr->width - (int)number_length - 1)
// 	{
// 		write(1, "0", 1);
// 		c++;
// 	}
// }

// void print_long_double(Formatter *fr, long double i, uintmax_t number_length, uintmax_t number_lenght_fact)
// {
// 	int c;

// 	c = 0;
// 	if (fr->flags[4] != '0')
// 		while (c < (int)fr->width - (int)number_lenght_fact)
// 		{
// 			write(1, " ", 1);
// 			c++;
// 		}
// 	if (i < 0)
// 	{
// 		write(1, "-", 1);
// 		c++;
// 	}
// 	else if (fr->flags[1] == '+' && i > 0)
// 	{
// 		write(1, "+", 1);
// 		c++;
// 	}
// 	if (fr->flags[4] == '0')
// 		print_long_double_1_1(fr, c, number_length);
// 	display_long_double(i, fr->precision, fr);
// }

// void field_width_resolver_long_double(Formatter *fr, long double i)
// {
// 	uintmax_t number_length;
// 	uintmax_t number_lenght_fact;

// 	if (fr->precision == -1)
// 		fr->precision = 6;
//     number_length = digit_counter_long_double(i, fr->precision, fr);
// 	number_lenght_fact = number_length_fact_double(fr, i, number_length);
// 	if (fr->width > number_lenght_fact)
// 	{
// 		if (fr->flags[0] == '-')
// 			print_left_alignment_long_double(fr, i, number_length);
// 		else
// 			print_long_double(fr, i, number_length, number_lenght_fact);
// 	}
// 	else
// 		print_long_double_1(fr, i);
// }

// void print_left_alignment_double(Formatter *fr, double i, uintmax_t number_length)
// {
// 	int c;

// 	c = 0;
// 	if (i > 0 && fr->flags[1] == '+')
// 	{
// 		write(1, "+", 1);
// 		c++;
// 	}
// 	if (i < 0)
// 	{
// 		write(1, "-", 1);
// 		c++;
// 	}
// 	display_double(i, fr->precision, fr);
// 	c += number_length;
// 	while(c < fr->width - 1)
// 	{
// 		write(1, " ", 1);
// 		c++;
// 	}			
// }

// void print_double(Formatter *fr, double i, uintmax_t number_length, uintmax_t number_lenght_fact)
// {
// 	int c;

// 	c = 0;
// 	if (fr->flags[4] != '0')
// 		while (c < (int)fr->width - (int)number_lenght_fact)
// 		{
// 			write(1, " ", 1);
// 			c++;
// 		}
// 	if (i < 0)
// 	{
// 		write(1, "-", 1);
// 		c++;
// 	}
// 	else if (fr->flags[1] == '+' && i > 0)
// 	{
// 		write(1, "+", 1);
// 		c++;
// 	}
// 	if (fr->flags[4] == '0')
// 		print_long_double_1_1(fr, c, number_length);
// 	display_double(i, fr->precision, fr);
// }

// void print_double_1(Formatter *fr, double i)
// {
// 	if (fr->flags[1] == '+' && i > 0)
// 		write(1, "+", 1);
// 	if (i < 0)
// 		write(1, "-", 1);
// 	display_double(i, fr->precision, fr);
// }

// void field_width_resolver_double(Formatter *fr, double i)
// {
// 	uintmax_t number_length;
// 	uintmax_t number_lenght_fact;

// 	if (fr->precision == -1)
// 		fr->precision = 6;
//     number_length = digit_counter_double(i, fr->precision, fr);
// 	number_lenght_fact = number_length_fact_double(fr, i, number_length);
// 	if (fr->width > number_lenght_fact)
// 	{
// 		if (fr->flags[0] == '-')
// 			print_left_alignment_double(fr, i, number_length);
// 		else
// 			print_double(fr, i, number_length, number_lenght_fact);
// 	}
// 	else
// 		print_double_1(fr, i);
// }

// uintmax_t number_length_fact_e(Formatter *fr, uintmax_t number_length, long double i)
// {
// 	uintmax_t number_lenght_fact;
	
// 	if ((fr->flags[1] == '+' || i < 0) && fr->precision != 0)
// 		number_lenght_fact = fr->precision + 5 + number_length;
// 	else if ((fr->flags[1] != '+') && fr->precision != 0)
// 		number_lenght_fact = fr->precision + 4 + number_length;
// 	else if (fr->precision == 0 && fr->flags[3] == '#' &&
// 			(fr->flags[1] == '+' || i < 0))
// 		number_lenght_fact = 5 + number_length;
// 	else if (fr->precision == 0 && fr->flags[3] == '#')
// 		number_lenght_fact = 4 + number_length;
// 	else if (fr->precision == 0 && (fr->flags[1] == '+' || i < 0))
// 		number_lenght_fact = 4 + number_length;
// 	else
// 		number_lenght_fact = 3 + number_length;
// 	return (number_lenght_fact);
// }

// void print_e_left_alignment(Formatter *fr, long double i, uintmax_t number_lenght_fact)
// {
// 	int c;

// 	c = 0;
// 	if (i > 0 && fr->flags[1] == '+')
// 			write(1, "+", 1);
// 		if (i < 0)
// 			write(1, "-", 1);
// 		display_long_double_eE(i, fr->precision, fr, digit_counter_e_1(i, fr));
// 		c += number_lenght_fact;
// 		while(c < fr->width)
// 			write(1, " ", 1) && c++;
// }

// void print_e(Formatter *fr, long double i, uintmax_t number_lenght_fact)
// {
// 	int c;

// 	c = 0;
// 	if (fr->flags[4] != '0')
// 		while (c < (int)fr->width - (int)number_lenght_fact)
// 			write(1, " ", 1) && c++;
// 	if (i < 0)
// 		write(1, "-", 1);
// 	else if (fr->flags[1] == '+' && i > 0)
// 		write(1, "+", 1);
// 	if (fr->flags[4] == '0')
// 		while (c < (int)fr->width - (int)number_lenght_fact)
// 			write(1, "0", 1) && c++;
// 	display_long_double_eE(i, fr->precision, fr, digit_counter_e_1(i, fr));
// }

// void print_e_1(Formatter *fr, long double i)
// {
// 	if (fr->flags[1] == '+' && i > 0)
// 		write(1, "+", 1);
// 	if (i < 0)
// 		write(1, "-", 1);
// 	display_long_double_eE(i, fr->precision, fr, digit_counter_e_1(i, fr));
// }

// void field_width_resolver_e(Formatter *fr, long double i)
// {
// 	uintmax_t number_length;
// 	uintmax_t number_lenght_fact;

// 	if (inf_nan_detector_long_double(i))
// 	{
// 		print_nan_inf(fr, inf_nan_detector_long_double(i));
// 		return ;
// 	}
// 	if (fr->precision == -1)
// 		fr->precision = 6;
//     number_length = digit_counter_e(i, fr);
// 	if (number_length == 1)
// 		number_length++;	
// 	number_lenght_fact = number_length_fact_e(fr, number_length, i);
// 	if (fr->width > number_lenght_fact)
// 	{
// 		if (fr->flags[0] == '-')
// 			print_e_left_alignment(fr, i, number_lenght_fact);
// 		else
// 			print_e(fr, i, number_lenght_fact);
// 	}
// 	else
// 		print_e_1(fr, i);
// }

// void field_width_resolver_e_double(Formatter *fr, double i)
// {
// 	uintmax_t number_length;
// 	uintmax_t number_lenght_fact;

// 	if (inf_nan_detector_double(i))
// 	{
// 		print_nan_inf(fr, inf_nan_detector_double(i));
// 		return ;
// 	}
// 	if (fr->precision == -1)
// 		fr->precision = 6;
//     number_length = digit_counter_e(i, fr);
// 	if (number_length == 1)
// 		number_length++;	
// 	number_lenght_fact = number_length_fact_e(fr, number_length, i);
// 	if (fr->width > number_lenght_fact)
// 	{
// 		if (fr->flags[0] == '-')
// 			print_e_left_alignment(fr, i, number_lenght_fact);
// 		else
// 			print_e(fr, i, number_lenght_fact);
// 	}
// 	else
// 		print_e_1(fr, i);
// }

// uintmax_t number_length_fact_e_1(Formatter *fr, uintmax_t number_length, double i)
// {
// 	uintmax_t number_lenght_fact;
	
// 	if ((fr->flags[1] == '+' || i < 0) && fr->precision != 0)
// 		number_lenght_fact = fr->precision + 5 + number_length;
// 	else if ((fr->flags[1] != '+') && fr->precision != 0)
// 		number_lenght_fact = fr->precision + 4 + number_length;
// 	else if (fr->precision == 0 && fr->flags[3] == '#')
// 		number_lenght_fact = 4 + number_length;
// 	else
// 		number_lenght_fact = 3 + number_length;
// 	return (number_lenght_fact);
// }

// void field_width_resolver_e_double_1(Formatter *fr, double i)
// {
// 	uintmax_t number_length;
// 	uintmax_t number_lenght_fact;

// 	if (fr->precision == -1)
// 		fr->precision = 6;
//     number_length = digit_counter_e(i, fr);
// 	if (number_length == 1)
// 		number_length++;
// 	number_lenght_fact = number_length_fact_e_1(fr, number_length, i);
// 	if (fr->width > number_lenght_fact)
// 	{
// 		if (fr->flags[0] == '-')
// 			print_e_left_alignment(fr, i, number_lenght_fact);		
// 		else
// 			print_e(fr, i, number_lenght_fact);
// 	}
// 	else
// 		print_e_1(fr, i);
// }

// void field_width_resolver_double_2(Formatter *fr, double i)
// {
// 	int count_prec;
// 	int c;
// 	uintmax_t number_length;
// 	uintmax_t number_lenght_fact;

// 	if (fr->precision == -1)
// 		fr->precision = 6;
//     number_length = digit_counter_long_double(i, fr->precision, fr);
// 	c = 0;
// 	if (fr->flags[1] == '+' || i < 0)
// 		number_lenght_fact = number_length + 1;
// 	else
// 		number_lenght_fact = number_length;
// 	if (fr->width > number_lenght_fact)
// 	{
// 		if (fr->flags[0] == '-')
// 		{
// 			print_left_alignment_double(fr, i, number_length);
// 			// if (i > 0 && fr->flags[1] == '+')
// 			// {
// 			// 	write(1, "+", 1);
// 			// 	c++;
// 			// }
// 			// if (i < 0)
// 			// {
// 			// 	write(1, "-", 1);
// 			// 	c++;
// 			// }
// 			// // count_prec = 0;
// 			// display_double(i, fr->precision, fr);
// 			// c += number_length;
// 			// while(c < fr->width - 1)
// 			// {
// 			// 	write(1, " ", 1);
// 			// 	c++;
// 			// }			
// 		}
// 		else
// 		{
// 			print_double(fr, i, number_length, number_lenght_fact);
// 			// if (fr->flags[4] != '0')
// 			// 	while (c < fr->width - number_lenght_fact - 1)
// 			// 	{
// 			// 		write(1, " ", 1);
// 			// 		c++;
// 			// 	}
// 			// if (i < 0)
// 			// {
// 			// 	write(1, "-", 1);
// 			// 	c++;
// 			// }
// 			// else if (fr->flags[1] == '+' && i > 0)
// 			// {
// 			// 	write(1, "+", 1);
// 			// 	c++;
// 			// }
// 			// if (fr->flags[4] == '0')
// 			// 	while (c < (int)fr->width - (int)number_length - 1)
// 			// 	{
// 			// 		write(1, "0", 1);
// 			// 		c++;
// 			// 	}
// 			// display_double(i, fr->precision, fr);
// 		}
// 	}
// 	else
// 	{
// 		print_double_1(fr, i);
// 		// if (fr->flags[1] == '+' && i > 0)
// 		// 	write(1, "+", 1);
// 		// if (i < 0)
// 		// 	write(1, "-", 1);
// 		// display_double(i, fr->precision, fr);
// 	}
// }

// int precision_recalculate_2_helper_1(int *mass, union long_double *f, long double num, uintmax_t precision)
// {
// 	intmax_t i;
// 	int u;

// 	f->f = num;
// 	i = 0;
//     while (i < 16500)
// 	{
// 		mass[i] = 0;
// 		i++;
// 	}
// 	u = f->bin.exp - 16383 - 63;
//     put_in_intmass(mass, f->bin.frac);
// 	i = 0;
// 	while (i < (-1 * u))
// 	{
// 		intmass_multiply(mass, 5);
// 		i++;
// 	}
// 	i = 16499;
// 	while (mass[i] == 0)
// 		i--;
// 	rounder_double(mass, precision, i);
// 	return (u);
// }

// int precision_recalculate_2_helper_2(Formatter *fr, int *c, long double num, int *mass)
// {
// 	int reculc_help;
// 	int reculc_help_2;

// 	reculc_help = 0;
// 	reculc_help_2 = 0;
// 	while (mass[c[0]] == 0)
// 	{
// 		c[0]--;
// 		reculc_help++;
// 		reculc_help_2++;
// 	}
// 	if (fr->flags[3] == '#' && num < 1 && num > -1)
// 		return (c[1] + reculc_help_2 - 1);
// 	while (reculc_help < reculc_help_2 + c[1] - 1 && c[0] > 0)
// 	{
// 		c[0]--;
// 		reculc_help++;
// 	}
// 	while (mass[c[0]] == 0)
// 	{
// 		c[0]++;
// 		reculc_help--;
// 	}
// 	return (reculc_help);
// }

// int precision_recalculate_2(long double num, uintmax_t precision, Formatter *fr)
// {
// 	int mass[16500];
//     int c[2];
//     union long_double f;

// 	if (fr->flags[3] == '#' && (num > 1 || num < -1))
// 		return (precision - 1);
// 	c[0] = -1 * precision_recalculate_2_helper_1(mass, &f, num, precision);
// 	c[1] = precision;
// 	return(precision_recalculate_2_helper_2(fr, c, num, mass));
// }

// int precision_recalculate_help_1(union long_double *f, int *mass, long double num)
// {
// 	int i;
// 	int u;
	
// 	f->f = num;
// 	u = f->bin.exp - 16383 - 63;
//     put_in_intmass(mass, f->bin.frac);
// 	i = 0;
// 	if (u >= 0)
// 		while (i < u)
// 		{
// 			intmass_multiply(mass, 2);
// 			i++;
// 		}
// 	else
// 		while (i < (-1 * u))
// 		{
// 			intmass_multiply(mass, 5);
// 			i++;
// 		}
// 	return (u);
// }

// int precision_recalculate_help_2(uintmax_t precision, int u, int *mass)
// {
// 	int reculc_help;
	
// 	rounder_double(mass, precision, (-1 * u));
// 	if ((int)precision > -1 * u)
// 		reculc_help = 0;
// 	else
// 		reculc_help = -1 * u - precision;
// 	while (reculc_help < (-1 * u) && mass[reculc_help] == 0)
// 		reculc_help++;
// 	return (-1 * u - reculc_help);
// }

// int precision_recalculate(long double num, uintmax_t precision, Formatter *fr)
// {
// 	int i;
// 	int mass[16500];
//     int u;
//     union long_double f;

// 	if (fr->flags[3] == '#')
// 		return (precision);
// 	i = 0;
//     while (i < 16500)
// 	{
// 		mass[i] = 0;
// 		i++;
// 	}
// 	u = precision_recalculate_help_1(&f, mass, num);
// 	if (u < 0)
// 		return(precision_recalculate_help_2(precision, u, mass));
//    	return (precision);
// }

// int precision_recalculate_help_3(long double num, uintmax_t precision, int *mass)
// {
// 	int i;
// 	int reculc_help;

// 	reculc_help = 0;
// 	if (num > -1 && num < 1)
// 	{
// 		i = 16499;
// 		while (mass[i] == 0) 
// 			i--;
// 		rounder_double(mass, precision, i);
// 	}
// 	i = 16499;
// 	while (mass[i] == 0) 
// 		i--;
// 	if ((int)precision - 1 > i)
// 		reculc_help = 0;
// 	else
// 		reculc_help = i - precision + 1;
// 	while (mass[reculc_help] == 0 && reculc_help < i)
// 		reculc_help++;
// 	return(i - reculc_help);
// }

// int precision_recalculate_1(long double num, uintmax_t precision, Formatter *fr)
// {
// 	int mass[16500];
//     int i;
//     int u;
//     union long_double f;

// 	if (fr->flags[3] == '#')
// 		return (precision - 1);
// 	if (precision == 0)
// 		return (0);
//     i = 0;
//     while (i < 16500)
// 	{
// 		mass[i] = 0;
// 		i++;
// 	}
// 	u = precision_recalculate_help_1(&f, mass, num);
// 	return (precision_recalculate_help_3(num, precision, mass));
// }

void router_1(int digit_amount, Formatter *fr, double i)
{
	if (digit_amount < -4)
	{
		fr->precision = precision_recalculate_1(i, fr->precision, fr);
		field_width_resolver_e_double(fr, i);
	}
	else if (digit_amount <= 0 && digit_amount >= -4)
	{
		fr->precision = precision_recalculate_2((long double)i, fr->precision, fr);
		field_width_resolver_double(fr, i);
	}
	else if (fr->precision <= digit_amount)
	{
		fr->precision = precision_recalculate_1((long double)i, fr->precision, fr);
		field_width_resolver_e_double(fr, i);
	}
	else
	{
		fr->precision = precision_recalculate((long double)i, fr->precision - digit_amount - 1, fr);
		field_width_resolver_double(fr, i);
	}
}

void field_width_resolver_gG_double(Formatter *fr, double i)
{
	int digit_amount;

	if (inf_nan_detector_double(i))
	{
		print_nan_inf(fr, inf_nan_detector_double(i));
		return ;
	}
	if (fr->precision == -1)
		fr->precision = 6;
	digit_amount = digit_counter_e_2((long double)i, fr);
	router_1(digit_amount, fr, i);
}

void router_2(int digit_amount, Formatter *fr, long double i)
{
	if (digit_amount < -4)
	{
		fr->precision = precision_recalculate_1(i, fr->precision, fr);
		field_width_resolver_e(fr, i);
	}
	else if (digit_amount <= 0 && digit_amount >= -4)
	{
		fr->precision = precision_recalculate_2(i, fr->precision, fr);
		field_width_resolver_long_double(fr, i);
	}
	else if (fr->precision <= digit_amount)
	{
		fr->precision = precision_recalculate_1(i, fr->precision, fr);
		field_width_resolver_e(fr, i);
	}
	else
	{
		fr->precision = precision_recalculate(i, fr->precision - digit_amount - 1, fr);
		field_width_resolver_long_double(fr, i);
	}
}

void field_width_resolver_gG_long_double(Formatter *fr, long double i)
{
	int digit_amount;

	digit_amount = digit_counter_e_2(i, fr);
	if (fr->precision == -1)
		fr->precision = 6;
	
	if (inf_nan_detector_long_double(i)
	{
		print_nan_inf(fr, inf_nan_detector_long_double(i);
		return ;
	}
	router_2(digit_amount, fr, i);
}