#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    char num;
    
    if (n >= 10)
        ft_putnbr_fd(n / 10, fd);
    num = n % 10 + 48;
    ft_putchar_fd(num, fd);
}