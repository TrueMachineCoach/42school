/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by bandrow           #+#    #+#             */
/*   Updated: 2019/11/23 20:45:45 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct	s_bin {
	uintmax_t	frac : 64;
	unsigned	exp : 15;
	unsigned	sign : 1;
}				t_bin;

union			long_double {
	t_bin		bin;
	long double	f;
};

typedef struct	s_bin2 {
	uintmax_t	frac : 52;
	unsigned	exp : 11;
	unsigned	sign : 1;
}				t_bin2;

union			double_double {
	t_bin2		bin;
	double		f;
};

typedef struct	s_formatter
{
	va_list		*ap;
	char		*str;
	size_t		c;
	char		flags[5];
	char		*color;
	size_t		width;
	int			precision;
	char		length[3];
	char		specifier;
	int			baks;
}				Formatter;

int				print_percent(Formatter *fr);
int				reculc_help_helper(Formatter *fr, int reculc_help);
int				print_e_1(Formatter *fr, long double i,
				uintmax_t number_lenght_fact);
void			print_e(Formatter *fr, long double i, uintmax_t number_lenght_fact);
void			print_e_left_alignment(Formatter *fr,
				long double i, uintmax_t number_lenght_fact);
uintmax_t		number_length_fact_e(Formatter *fr,
				uintmax_t number_length, long double i);
uintmax_t		digit_counter_e(long double num,
				Formatter *fr);
uintmax_t		digit_counter_e_1(long double num,
				Formatter *fr);
uintmax_t		digit_counter_double(double num1,
				uintmax_t precision, Formatter *fr);
int				print_long_double_1_1(Formatter *fr,
				int c, uintmax_t number_length);
uintmax_t		number_length_fact_double(Formatter *fr,
				long double i, uintmax_t number_length);
uintmax_t		digit_counter_long_double(long double num,
				uintmax_t precision, Formatter *fr);
uintmax_t		number_lenght_fact_ox(Formatter *fr, int number_length);
uintmax_t		number_lenght_fact_signed(Formatter *fr,
				int number_length, intmax_t i);
void			print_positive_presision_signed_helper(Formatter *fr,
				intmax_t i, int c, int number_length);
uintmax_t		digit_counter_e_2(long double num, Formatter *fr);
int				precision_recalculate(long double num,
				uintmax_t precision, Formatter *fr);
int				precision_recalculate_1(long double num, uintmax_t precision,
				Formatter *fr);
int				precision_recalculate_2(long double num,
				uintmax_t precision, Formatter *fr);
int				field_width_resolver_e_double(Formatter *fr, double i);
int				field_width_resolver_e(Formatter *fr, long double i);
int				resolver_diu2(uintmax_t *ui, Formatter *fr);
int				ft_printf(char *format, ...);
int				parse(Formatter *fr, va_list *args);
void			parse_flags(Formatter *fr);
int				parse_width(Formatter *fr, va_list *args);
int				parse_precision(Formatter *fr, va_list *args);
void			parse_length(Formatter *fr);
void			parse_specifier(Formatter *fr);
va_list			*parse_baks(Formatter *fr, va_list *args);
int				resolver(Formatter *fr);
char  			*itoa_base(uintmax_t num, int base, char spec);
void			display_float(long double num, Formatter *fr, uintmax_t j, uintmax_t count);
void			display_float_1(double num, Formatter *fr, uintmax_t j, uintmax_t count);
void			integer_separator_double(double num);
void			display_long_double(long double num, uintmax_t precision, Formatter *fr);
void			display_double(double num, uintmax_t precision, Formatter *fr);
void			print_binary(void *arg);
void			handle_data(Formatter *fr, uintmax_t i);
void			field_width_resolver(Formatter *fr, intmax_t i);
int				field_width_resolver_unsigned(Formatter *fr, uintmax_t i);
void			display_diu_unsigned(uintmax_t i);
void			display_diu_signed(Formatter *fr, intmax_t i);
void			intmass_multiply(int *test, int k);
void			put_in_intmass(int *dest, uintmax_t src);
void			put_in_intmass_double(int *help,int *dest, uintmax_t src);
int				field_width_resolver_double(Formatter *fr, double i);
void			display_long_double_eE(long double num, uintmax_t precision, Formatter *fr, uintmax_t number_length);
void			field_width_resolver_eE(Formatter *fr, long double i);
void			rounder_double(int *mass, uintmax_t precision, uintmax_t delimiter);
void			field_width_resolver_eE_double(Formatter *fr, double i);
void			field_width_resolver_gG_double(Formatter *fr, double i);
int				print_pointer(Formatter *fr);
int				inf_nan_detector(Formatter *fr, va_list *ap);
void			hash_management(Formatter *fr, va_list *ap);
void			print_flag_e(Formatter *fr, va_list *ap);
void			print_flag_g(Formatter *fr, va_list *ap);
void			print_color();
int	 			field_width_resolver_g_long_double(Formatter *fr, long double i);
uintmax_t		number_lenght_fact_definer_signed(Formatter *fr,
				int number_length, intmax_t i);
uintmax_t		number_lenght_fact_definer_unsigned(Formatter *fr,
				int number_length);
int				number_length_counter_unsigned(uintmax_t i, int base);
void			print_left_alignment_help(Formatter *fr,
				int number_length, int c);
void			print_signed_left_alignment(Formatter *fr,
				int number_length, intmax_t i);
int				parse(Formatter *fr, va_list *args);
void			parse_flags(Formatter *fr);
int				parse_width(Formatter *fr, va_list *args);
int				parse_precision(Formatter *fr, va_list *args);
void			parse_length(Formatter *fr);
void			parse_specifier(Formatter *fr);
va_list			*parse_baks(Formatter *fr, va_list *args);
char			*itoa_base(uintmax_t num, int base, char spec);
void			display_float(long double num, Formatter *fr,
								uintmax_t j, uintmax_t count);
void			display_float_1(double num, Formatter *fr,
								uintmax_t j, uintmax_t count);
void			integer_separator_double(double num);
void			display_long_double(long double num,
								uintmax_t precision, Formatter *fr);
void			display_double(double num, uintmax_t precision,
								Formatter *fr);
void			print_binary(void *arg);
int				print_non_printable(char *str);
void			handle_data(Formatter *fr, uintmax_t i);
void			display_diu_unsigned(uintmax_t i);
void			display_diu_signed(Formatter *fr, intmax_t i);
int				field_width_resolver_oxX(Formatter *fr, uintmax_t i);
void			intmass_multiply(int *test, int k);
void			put_in_intmass(int *dest, uintmax_t src);
void			put_in_intmass_double(int *help, int *dest, uintmax_t src);
int				field_width_resolver_long_double(Formatter *fr,
									long double i);
void			display_long_double_eE(long double num, uintmax_t precision,
									Formatter *fr, uintmax_t number_length);
void			field_width_resolver_eE(Formatter *fr, long double i);
void			rounder_double(int *mass, uintmax_t precision,
									uintmax_t delimiter);
void			field_width_resolver_eE_double(Formatter *fr, double i);
int				field_width_resolver_g_double(Formatter *fr, double i);
int				inf_nan_detector_double(double num);
int				inf_nan_detector_long_double(long double num);
int				print_nan_inf(Formatter *fr, int k);
int				inf_nan_detector(Formatter *fr, va_list *ap);
void			hash_management(Formatter *fr, va_list *ap);
void			print_flag_e(Formatter *fr, va_list *ap);
void			print_flag_g(Formatter *fr, va_list *ap);
void			print_color();
int				print_str(Formatter *fr);
int				print_char(Formatter *fr);
int				pprint_str(char *str, size_t size);
int				print_date(Formatter *fr);
void			field_width_resolver_gG_long_double(Formatter *fr,
									long double i);
void			print_inf_nan_1(int *x);
void			print_inf_nan_2(int *i, size_t *j);
void			put_multiply_2x5_array(int *mass, int *u, int *i);
void			put_zero_to_array(int *mass, int *i);
void			finder_not_zero(int *mass, int *i);

#endif
