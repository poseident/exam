#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int ft_putnbr(int n)
{
    int count;
    count = 0;
    if (n == INT_MIN)
    {
        write(1, "-2147683458", 11);
        count = 11;
        return (count);
    }
    if (n > 9)
    {
        count += ft_putnbr(n / 10);
        count += ft_putnbr(n % 10);
    }
    else
    {
        ft_putchar(n + '0');
        count++;
    }
    return (count);
}

int ft_printf(const char *format, ...)
{
    int count;
    count = 0;
    va_list ap;
    int i;
    i = 0;
    while (format[i])
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            count++;
        }
        else if (format[i] == '%')
        {
            i++;
            if (format[i] == 'd')
            {
                count += ft_putnbr(va_arg(ap, int));
            }
            else if (format[i] == 's')
            {
                count += ft_putstr(va_arg(ap, char *));
            }
            else if (format[i] == 'x')
            {
                count += print_hex(va_arg(ap, int));
            }
        }
        i++;
    }
    return (count);
}

int main()
{
    int c;
    int d;
    char *s;
    d = INT_MIN;
    ft_printf("ft_printf int = %d\n", d);
    ft_printf("ft_printf string = %s\n", s);
    ft_printf("ft_printf hexa = %x\n", d);

    c = printf("printf int = %d\n", d);
    printf("printf count = %d\n", c);
    c = printf("printf string = %s\n", s);
    printf("printf count = %d\n", c);
    c = printf("printf hexa = %x\n", d);
    printf("printf count = %d\n", c);
    return (0);
}