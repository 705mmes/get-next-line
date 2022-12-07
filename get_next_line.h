/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:31:54 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/05 13:54:43 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
// #ifndef BUFFERSIZE

// # define BUFFERSIZE

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> 
# include <fcntl.h>

void	ft_putstr(char *str);
char	*get_next_line(int fd);
void	ft_putchar(char c);

#endif
