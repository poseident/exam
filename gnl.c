#include "gnl.h"

char	*get_next_line(int fd)
{
    static char *str;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    str = read_str(fd, str);
    if (!str)
        return (NULL);
    line = str_line(str);
    str = clean_str(str);
    return (line);
}

char *clean_str(char *str)
{
    int i;
    int d;
    char *line;
    i = 0;
    d = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
	{
		free(str);
		return (NULL);
	}
    line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (str[i] == '\n')
        i++;
    while (str[i])
    {
        line[d] = str[i];
        i++;
        d++;
    }
    line[d] = '\0';
    return (line);
}

char *str_line(char *str)
{
    int i;
    char *line;
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
        return (NULL);
    line = malloc(sizeof(char) * i + 2);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return (line);
}

char *read_str(int fd, char *str)
{
    int readed;
    char *buf;

    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    readed = 1;
    while (readed != 0 && !ft_strchr(str, '\n'))
    {
        readed = read(fd, buf, BUFFER_SIZE);
        if (readed == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[readed] = '\0';
        str = ft_strjoin(buf, str);
    }
    free(buf);
    return (str);
}

int main()
{
    int fd1 = open("foo.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd1);
    printf("%s", line);
    line = get_next_line(fd1);
    printf("%s", line);
    line = get_next_line(fd1);
    printf("%s", line);
    line = get_next_line(fd1);
    printf("%s", line);
    line = get_next_line(fd1);
    printf("%s", line);
    line = get_next_line(fd1);
    printf("%s", line);
    close(fd1);
    return 0;
}