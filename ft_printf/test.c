#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

// union FLOAT {
//     struct {
//         unsigned frac : 23;
//         unsigned exp : 8;
//         unsigned sign : 1;
//     } bin;
//     float f;
// };

// void put_in_intmass(int *dest, uintmax_t src)
// {
// 	while (src / 10)
// 	{
// 		*dest = src % 10;
// 		dest++;
// 		src = src / 10;
// 	}
// 	*dest = src % 10;
// }

// void intmass_multiply(int *test, int k)
// {
// 	int i;
// 	int reminder;

// 	i = 0;
// 	reminder = 0;
// 	while (i < 5000)
// 	{
// 		test[i] = test[i] * k + reminder;
// 		if (test[i] > 9)
// 		{
// 			reminder = test[i] / 10;
// 			test[i] = test[i] % 10; 
// 		}
// 		else
// 			reminder = 0;
// 		i++;
// 	}
// }

// void intmass_plus(int *test, int *test2)
// {
// 	int i;
// 	int reminder;

// 	i = 0;
// 	reminder = 0;
// 	while (i < 5000)
// 	{
// 		test[i] = test[i] + test2[i] + reminder;
// 		if (test[i] > 9)
// 		{
// 			reminder = test[i] / 10;
// 			test[i] = test[i] % 10;
// 		}
// 		else
// 			reminder = 0;
// 		i++;
// 	}
// }

// union LONG_DOUBLE {
//     struct {
//         unsigned long long frac : 64;
//         unsigned exp : 15;
//         unsigned sign : 1;
//     } bin;
//     long double f;
// };

// // union LONG_DOUBLE_HELPER {
// //      number : 16385;
// // 	unsigned sign : 1;
// //     long double f;
// // };

// // typedef union s_FLOAT
// // {
// // 	/*struct {
// // 		unsigned fract : 23;
// // 		unsigned exp : 8;
// // 		unsigned sign : 1;
// // 	} bin;*/
// // 	float f;
// // 	uint32_t dw;
// // }				FLOAT;

// // union FLOAT {
// //     struct {
// //         unsigned frac : 23;
// //         unsigned exp : 8;
// //         unsigned sign : 1;
// //     } bin;
// //     float f;
// // };

// // int main()
// // {
// // 	float f = 1.95;
// // 	FLOAT f_bin;
// // 	f_bin.f = f;


// // 	// float h;
// // 	// int i;
// // 	// int c;
// // 	// int g;

// // 	// h = 1.65;
// // 	// h = h * 10;
// // 	// h = h * 10; 
// // 	// c = -1;
// // 	// i = 0;
// // 	// while (i < 32)
// // 	// {
// // 	// 	c = c << i;
// // 	// 	g = 1;
// // 	// 	g = g << 31;
// // 	// 	// printf("%d\n", g);
// // 	// 	c = c & g;
// // 	// 	c = c >> 31;
// // 	// 	c = c & 1;
// // 	// 	printf("%d", c);
// // 	// 	i++;
// // 	// 	c = -1;
// // 	// }
// // 	return (0);
// // }


// // #define MAXPOWTWO	4.503599627370496000E+15
// // 			/* doubles >= MAXPOWTWO are already integers */
// // double	modf(double value, double *iptr)
// // {
// // 	double absvalue;

// // 	if ((absvalue = (value >= 0.0) ? value : -value) >= MAXPOWTWO)
// // 		*iptr = value; /* it must be an integer */
// // 	else {
// // 		*iptr = absvalue + MAXPOWTWO; /* shift fraction off right */
// // 		*iptr -= MAXPOWTWO; /* shift back without fraction */
// // 		while (*iptr > absvalue) /* above arithmetic might round */
// // 			*iptr -= 1.0; /* test again just to be sure */
// // 		if (value < 0.0)
// // 			*iptr = -*iptr;
// // 	}
// // 	return (*iptr); /* signed fractional part */
// // }

// // union FLOAT {
// //     struct {
// //         unsigned frac : 23;
// //         unsigned exp : 8;
// //         unsigned sign : 1;
// //     } bin;
// //     float f;
// // };
 
int main()
{
	// uintmax_t c;
	long double k;          
    int i;
	// int u;            
    // union LONG_DOUBLE f;
	// int test[5000];
	// unsigned long long k1 = 2ULL;
	
	// u = 16383;
	k = 999.99999;
	i = 1;
	// while (i < 16383)
	// {
	// 	k = k * 2.0;
	// 	i++;
	// }
	// display_double(k, 1);
	// i = 0;
	// while (i < 5000)
	// {
	// 	test[i] = 0;
	// 	i++;
	// }
	// i = 5000;
	// // while (i >= 0)
	// // {
	// // 	printf("%d", test[i]);
	// // 	i--;
	// // }
	// put_in_intmass(test, k1);
	// // put_in_intmass(test2, k1);
	// // intmass_plus(test, test2);
	// i = 1;
	// while (i < 1000)
	// {
	// 	intmass_multiply(test, 2);
	// 	i++;
	// 	/* code */
	// }
	// intmass_multiply(test, 2);
	// c = 18446744073709551615ULL;
	// f.bin.frac = f.bin.frac && c;
	// f.bin.frac = f.bin.frac + 1;
	// f.f = 5.0;
	// i = 19;
	// while (i >= 0)
	// {
	// 	printf("%d", test[i]);
	// 	i--;
	// }

	// i = 4999;
	// u = f.bin.exp - 16383 - 63;
	// printf("%d\n", u);
	// i = 1;
	// put_in_intmass(test, f.bin.frac);
	// i = 4999;
	// while (test[i] == 0)
	// 	i--;
	// // printf("\n\n\n\n\n");
	// printf("\n%llu\n", f.bin.frac);
	// while (i >= 0)
	// {
	// 	if (i == (-1 * u))
	// 		printf(".");
	// 	printf("%d", test[i]);
	// 	i--;
	// }
	// i = 0;
	// if (u >= 0)
	// {
	// 	while (i < u)
	// 	{
	// 		intmass_multiply(test, 2);
	// 		i++;
	// 	}
	// }
	// else
	// {
	// 	while (i < (-1 * u))
	// 	{
	// 		intmass_multiply(test, 5);
	// 		i++;
	// 	}
	// }
	// i = 4999;
	// while (test[i] == 0)
	// 	i--;
	// // printf("\n\n\n\n\n");
	// printf("\n\n");
	// while (i >= 0)
	// {
	// 	if (i == ((-1 * u) - 1))
	// 		printf(".");
	// 	printf("%d", test[i]);
	// 	i--;
	// }
    // printf("\n\n%.100Lf %d, %llu, %d", f.f, (f.bin.exp - 16383), f.bin.frac, f.bin.sign);
    printf("\n%.1Lf", k);
    return 0;
}