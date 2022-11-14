#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
    int num;
    int i;
    int sign;

    i = 0;
    num = 0;
    sign = 1;
    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num * sign);
}

void    prime(char *str)
{
    int num;
    int i;

    i = 2;
    num = ft_atoi(str);
    while (i <= num)
    {
        if (num % i == 0)
        {
            printf("%d", i);
            if (i != num)
                printf("*");
            num /= i;
            i--;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        prime(argv[1]);
    write(1, "\n", 1);
}