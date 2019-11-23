#include "libft.h"

// void	test_memcmp()
// {
// 	char *str1 = "Hello, world!";
// 	char *str2 = "Hello, world!";

// 	int myfunc = ft_memcmp(str1, str2, ft_strlen(str1));
// 	int libfunc = memcmp(str1, str2, ft_strlen(str2));
// 	printf("TEST - ft_memcmp:  %s (str1 - %s, str2 - %s)\n", (myfunc == libfunc? "OK" : "FAIL"), str1, str2);	
		
// 	str1 = "aaacbscaw";
// 	str2 = "zsdawdawih";

// 	myfunc = ft_memcmp(str1, str2, ft_strlen(str1));
// 	libfunc = memcmp(str1, str2, ft_strlen(str2));
// 	printf("TEST - ft_memcmp:  %s (str1 - %s, str2 - %s)\n", (myfunc == libfunc? "OK" : "FAIL"), str1, str2);	

// 	str1 = "Abcpqjd";
// 	str2 = "zsdawdawih";

// 	myfunc = ft_memcmp(str1, str2, ft_strlen(str1));
// 	libfunc = memcmp(str1, str2, ft_strlen(str2));
	
// 	str1 = "dwad";
// 	str2 = "ldwa";

// 	myfunc = ft_memcmp(str1, str2, ft_strlen(str1));
// 	libfunc = memcmp(str1, str2, ft_strlen(str2));
// 	printf("TEST - ft_memcmp:  %s (str1 - %s, str2 - %s)\n", (myfunc == libfunc? "OK" : "FAIL"), str1, str2);	
// }

void	test_strcat()
{
	char dst[100] = "lol ";
	char *src = "hello, world!";

	printf("%s", ft_strcat(dst, src));
}