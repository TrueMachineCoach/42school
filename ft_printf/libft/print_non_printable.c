// #include "libft/libft.h"
// #include "ft_printf/ft_printf.h"
#include <unistd.h>

void print_non_printable(char *str)
{
    while (*str)
    {
        if (*str < 16 && *str >= 0)
        {
            write(1, "\\x0", 3); 
            write(1, &(*str), 1);
        }
        if (*str >=16 && *str < 32)
        {
            write(1, "\\x", 2); 
            write(1, &(*str), 1);
        }
        str++;
    }
}

int main(int argc, char **argv)
{
    print_non_printable("\n\n\n\n");
    return (0);
}