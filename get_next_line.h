/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:51:17 by bschweit          #+#    #+#             */
/*   Updated: 2022/05/18 16:21:05 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char		*found_new_line(char *string, int c);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*read_to_stash(char *stash, int fd);
char		*stash_to_line(char *stash);
char		*clean_stash(char *stash);
char		*stash_with_new_line(char *stash);

#endif
