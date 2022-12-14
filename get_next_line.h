/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:14:20 by sammeuss          #+#    #+#             */
/*   Updated: 2023/01/03 16:37:43 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int *read_size, int i);
char	*ft_line(char *buffer, char *line, int *read_size);
char	*ft_read_until_backslash_n(char	*s, int fd, char *save, int *len_buff);
int		ft_strlen(char *s);
int		len_backslash_n(char *s, int *read_size, int choice);
int		ft_fill_save(char **save, int *read_size);
char	*free_item(char **s);
char	*double_free(char *s1, char **s2);
// char	*gnl_v2(char *save, char *line, int *read_size);

#endif