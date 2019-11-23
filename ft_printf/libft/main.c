/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:12:14 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/16 19:30:09 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>
//#include "test.h"
// void	test1(char *str)
// {
// 	printf("%lu", sizeof(str));
// }

int		main(void)
{
	// char str1[] = "123456789";
	// char str2[] = "123456789";

	// printf("%s\n", (char*)ft_memset(str1, '0', 11));
	// printf("%s\n", (char*)memset(str2, '0', 11));

	//ft_memcmp
	//test_memcmp();

	//ft_strcat
	//test_strcat();
	// char str[] ="helooldawdawdawdawdawd";
	// printf("%lu", sizeof(str));
	
	// char buf[10] = "lol ";
	// char *str = "hello, world";
	
	// printf("%s  -  %lu", buf, ft_strlcat(buf, str, sizeof(buf)));
	// printf("%s  -  %lu", buf, strlcat(buf, str, sizeof(buf)));
	
	// char *str = "Hello, eworld!";
	// char *ptr;

	// ptr = ft_strrchr(str, 'e');

	// char *haystack = "Hello, world!";
	// char dst1[15] = "a";
	// char dst2[15] = "a";

	// printf("My: %s         %lu\n", dst1, ft_strlcat(dst1, "lorem ipsum dolor sit amet", 15));
	// printf("lib: %s         %lu\n", dst2, strlcat(dst2, "lorem ipsum dolor sit amet", 15));
	
	// char dst1[15] = "";
	// char dst2[15] = "";
	// memset(dst1, 0, 15);
	// memset(dst2, 0, 15);
	// memset(dst1, 'r', 6);
	// memset(dst2, 'r', 6);
	// dst1[10] = 'a';
	// dst2[10] = 'a';

	// printf("MY: %lu  %c%s\n", ft_strlcat(dst1, "lorem ip sum dolor sit amet", 3), '|', dst1);
	// printf("LIb: %lu  %c%s\n", strlcat(dst2, "lorem ipsum dolor sit amet", 3),  '|', dst2);
	
	// printf("%s", ft_strtrim("Hello, world!     "));
	// char **arr;
	// int i;

	// arr = ft_strsplit("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	// i = 0;
	// while (arr[i])
	// {
	// 	printf("%s\n", arr[i]);
	// 	i++;
	// }
	//t_capitalizer("uPP");
	//ft_rev_wstr("Igor is     name      my  ");
	// char dst1[15];
	// char dst2[15];
	// char *src = "lorem ipsum dolor sit amet";
	
	// ft_bzero(dst1, 15);
	// ft_bzero(dst2, 15);	
	// ft_memset(dst1, 'r', 6);
	// ft_memset(dst2, 'r', 6);
	// dst1[10] = 'a';
	// dst2[10] = 'a';			
	// printf("%s - %lu\n", dst1, ft_strlcat(dst1, src, 0));
	// printf("%s - %lu", dst2, strlcat(dst2, src, 0));
	
	// printf("%d\n", atoi("-9223372036854775810"));
	// printf("%d\n", ft_atoi("-9223372036854775810"));
	
	char *str = "*hello*fellow***students*";
    char **arr;

    arr = ft_strsplit(str, '*');
    int i = 0;
    while (arr[i])
    {
        printf("%s ", arr[i]);
        i++;
    }
	return (0);
}

