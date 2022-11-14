#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int string(char *str)
{
    int i;

    i = 0;
    if (!str)
    {
        str = "(null)";
    }
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr(int m)
{
    int count;

    count = 0;
    if (m == INT_MIN)
    {
        write(1, "-2147483648", 11);
        count += 11;
        return (count);
    }
    if (m < 0)
    {
        write(1, "-", 1);
        m = -m;
        count++;
    }
    if (m > 9)
    {
        count += ft_putnbr(m / 10);
        count += ft_putnbr(m % 10);
    }
    else
    {
        ft_putchar(m + '0');
        count++;
    }
    return (count);
}

int print_hex(unsigned int n)
{
    char *str = "0123456789abcdef";
    int count;
    count = 0;
    if (n >= 16)
    {
        count += print_hex(n / 16);
        count += print_hex(n % 16);
    }
    else
    {
        ft_putchar(str[n % 16]);
        count++;
    }
    return (count);
}

int ft_printf(const char *format, ...)
{
    int count;
    int i;
    va_list ap;

    i = 0;
    count = 0;
    va_start(ap, format);
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
            if (format[i] == 's')
            {
                count += string(va_arg(ap, char *));
            }
            else if (format[i] == 'd')
            {
                count += ft_putnbr(va_arg(ap, int));
            }
            else if (format[i] == 'x')
            {
                count += print_hex(va_arg(ap, int));
            }
            else if (format[i] == '%')
            {
                write(1, &format[i], 1);
                count++;
            }
        }
        i++;
    }
    //printf("mine = %d\n", count);
    return (count);
}

int main()
{
    int c;
    int d;
    char *s;
    d = -10;
    ft_printf("ft_printf int = %d\n%%", d);
    ft_printf("ft_printf string = %s\n", s);
    ft_printf("ft_printf hexa = %x\n", d);

    c = printf("ft_printf%% int = %d\n", d);
    printf("printf count = %d\n", c);
    c = printf("ft_printf string = %s\n", s);
    printf("printf count = %d\n", c);
    c = printf("ft_printf hexa = %x\n", d);
    printf("printf count = %d\n", c);
    printf("bon %%\n");
    ft_printf(" oebon %%");
    return (0);
}