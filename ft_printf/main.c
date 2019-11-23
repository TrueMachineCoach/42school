#include <stdio.h>
#include "ft_printf.h"
#include <float.h>
#include <unistd.h>
#include <locale.h>
#include "libft/libft.h"

void reinitialize(Formatter *fr, int i)
{
	if (i == 0)
		fr->c = 0;
	fr->flags[0] = '\0';
	fr->flags[1] = '\0';
	fr->flags[2] = '\0';
	fr->flags[3] = '\0';
	fr->flags[4] = '\0';
	fr->baks = 0;
	fr->width = 0;
	fr->precision = -1;
	fr->length[0] = 0;
	fr->length[1] = 0;
	fr->length[2] = '\0';
	fr->specifier = 0;
	fr->ap = 0;
}

void	set_color(Formatter *fr, int *flag) {
	if (ft_strncmp(&fr->str[fr->c], "{red}", 5) == 0 && (fr->c += 5) && (*flag = 1))
		write(1, "\033[0;31m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{bred}", 6) == 0 && (fr->c += 6) && (*flag = 1))
		write(1, "\033[1;31m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{green}", 7) == 0 && (fr->c += 7) && (*flag = 1))
		write(1, "\033[0;32m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{bgreen}", 8) == 0 && (fr->c += 8) && (*flag = 1))
		write(1, "\033[1;32m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{yellow}", 8) == 0 && (fr->c += 8) && (*flag = 1))
		write(1, "\033[0;33m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{byellow}", 9) == 0 && (fr->c += 9) && (*flag = 1))
		write(1, "\033[01;33m", 8);
	else if (ft_strncmp(&fr->str[fr->c], "{blue}", 6) == 0 && (fr->c += 6) && (*flag = 1))
		write(1, "\033[0;34m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{bblue}", 7) == 0 && (fr->c += 7) && (*flag = 1))
		write(1, "\033[1;34m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{magenta}", 9) == 0 && (fr->c += 9) && (*flag = 1))
		write(1, "\033[0;35m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{bmagenta}", 10) == 0 && (fr->c += 10) && (*flag = 1))
		write(1, "\033[1;35m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{cyan}", 6) == 0 && (fr->c += 6) && (*flag = 1))
		write(1, "\033[0;36m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{bcyan}", 7) == 0 && (fr->c += 7) && (*flag = 1))
		write(1, "\033[1;36m", 7);
	else if (ft_strncmp(&fr->str[fr->c], "{eoc}", 5) == 0  && flag && (fr->c += 5))
		write(1, "\033[0m", 4);
}

int		ft_printf(char *format, ...)
{
	Formatter fr;
	va_list ap;
	int flag;
	int count;

	// void	i;
	flag = 0;
	count = 0;
	reinitialize(&fr, 0);
	va_start(ap, format);
	fr.str = format;
	while(fr.str[fr.c] != '\0')
	{
		while (fr.str[fr.c] != '%' && fr.str[fr.c] != '\0')
		{
			if (fr.str[fr.c] == '{')
				set_color(&fr, &flag);
			write(1, &(fr.str[fr.c]), 1);
			fr.c++;
			count++;
		}
		if (fr.str[fr.c] == '%')
		{
			// if (fr.str[fr.c + 1] == '%')
			// {
			// 	write(1, "%", 1);
			// 	fr.c = fr.c + 2;
			// }
			// else
			// {
			count += parse(&fr, &ap);
			reinitialize(&fr, 1);
			// }
		}
	}
	va_end(ap);
	return (count);
}

int main()
{
	// unsigned long long j;
	// short k;

	// i = 0;
	// c = 2.00;
	// z = -2800;
	// i = 0;
	// struct lconv l;
	// l.thousands_sep = "736252";
	// // j = 1844674407370955161;
	// while (i < 1023)
	// {
	// 	c = c * 2.00;
	// 	i++;
	// }
	// ft_printf("%#012.0i %---+----#0100.134g %+++++000002.47Le %#0000-129.102Lf %-464.80000Lg\n", 12345627, 9214612984.00000000008, LDBL_MAX, -0.00000000060000L, 001.999999999999999999L);
	// printf("%#012.0d %---+----#0100.134g %+++++000002.47Le %#0000-129.102Lf %-464.80000Lg\n", 12345627, 9214612984.00000000008, LDBL_MAX, -0.00000000060000L, 001.999999999999999999L);
	ft_printf("%#x\n", 0);
	printf("%#x", 0);
	// printf("%056.120Lg\n", 8372974.338L);
	// printf("%.80f\n", 2.00000000000/1);
	// ft_printf("%Lf", 89884656743115795386465259539451236680898848947115328636715040578866337902750481566354238661203768010560056939935696678829394884407208311246423715319737062188883946712432742638151109800623047059726541476042502884419075341171231440736956555270413618581675255342293149119973622969239858152417678164812112068608.0);
	// printf("\n%.1Lf\n", 89884656743115795386465259539451236680898848947115328636715040578866337902750481566354238661203768010560056939935696678829394884407208311246423715319737062188883946712432742638151109800623047059726541476042502884419075341171231440736956555270413618581675255342293149119973622969239858152417678164812112068608.0);
	// printf("\n%.100f\n", (c = c / 10)); 
	// printf("\n%.100f\n", (c = c / 10));
	// printf("\n%.100f\n", (c = 12298346423623420000000.0 * 100));
	// 	printf("\n");
	// k = 1;
	// printf("%2$-1.1llu %1$---1.1hx\n", k, j);
	// printf("%d\n", c);
	// printf("%d\n", c);
	// c = (unsigned int )c;
	// c = 4294967295;
	// printf("%u\n", 3000000000);
	// int c;

	// c = 289;
	// printf("%c", c);
	// char c = -5;
	// unsigned char tmp = c;

	// printf("%", &c);
	// return (0); 
}