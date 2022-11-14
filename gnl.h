#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# define BUFFER_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/resource.h>
# include <stdio.h>
# include <fcntl.h>

char		*get_next_line(int fd);
char        *read_str(int fd, char *str);
char *str_line(char *str);
char *clean_str(char *str);

//utils:

int ft_strchr(char *str, char c);
int ft_strlen(char *str);
char *ft_strjoin(char *buf, char *str);

#endif