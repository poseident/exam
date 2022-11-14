#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int num_len(int nbr)
{
    int i;

    i = 0;
    if (nbr <= 0)
        i++;
    while (nbr != 0)
    {
        i++;
        nbr /= 10;
    }
    return (i);
}

char	*ft_itoa(int nbr)
{
    int len;
    int i;
    char *str;

    i = 0;
    len = num_len(nbr);
    str = malloc(sizeof(char) * len + 1);
    printf("%d\n", INT_MIN);
    str[len] = '\0';
    len--;
    if (nbr == -2147483648)
    {
        str = "-2147483648";
        return (str);
    }
    if (nbr < 0)
    {
        str[0] = '-';
        nbr = -nbr;
    }
    while (nbr != 0)
    {
        str[len] = (nbr % 10) + '0';
        len--;
        nbr /= 10;
    }
    return (str);
}

int main(int argc, char **argv)
{
    printf("%s\n", ft_itoa(-2147483648));
    return (0);
}