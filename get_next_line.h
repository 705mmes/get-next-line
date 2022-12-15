/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:14:20 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/14 21:59:01 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFERSIZE
#  define BUFFERSIZE 9
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_line(char *buffer, char *line);
char	*ft_read_until_backslash_n(char	*s, int fd, char *save, int *len_buff);
int		ft_strlen(char *s);
int		ft_strlen_backslash_n(char *s);
char	*ft_fill_save(char *save, char *buffer, int len_buff, char *line);
// char	*check_read(char *buffer);

#endif