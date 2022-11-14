#include "gnl.h"

int ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char *ft_strjoin(char *buf, char *str)
{
    int i;
    int j;
    char *line;

    i = 0;
    j = 0;
    if (!str)
    {
        str = malloc(sizeof(char) * 1);
        str[0] = '\0';
    }
    line = malloc(sizeof(char) * (ft_strlen(buf) + (ft_strlen(str)) + 1));
    while (str[i])
    {
        line[i] = str[i];
        i++;
    }
    while (buf[j])
    {
        line[i] = buf[j];
        i++;
        j++;
    }
    line[i] = '\0';
    free(str);
    return (line);
}