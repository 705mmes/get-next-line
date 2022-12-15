/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:14:20 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/15 16:43:36 by smunio           ###   ########.fr       */
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
char	*ft_strjoin(char *s1, char *s2, int *read_size);
char	*ft_line(char *buffer, char *line, int *read_size);
char	*ft_read_until_backslash_n(char	*s, int fd, char *save, int *len_buff);
int		ft_strlen(char *s);
int		ft_strlen_backslash_n(char *s, int *read_size);
char	*ft_fill_save(char *save);

#endif