/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:31:22 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/05 14:23:37 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	int			buffer_size;
	int			i;
	int			u;
	static char	*poubelle;

	u = 0;
	i = 0;
	buffer_size = 26;
	buffer = malloc(sizeof(char) * buffer_size);
	if (!buffer)
		return (0);
  	read(fd, buffer, buffer_size);
	while (buffer[i] != '\n')
		i++;
	result = malloc(sizeof(char) * i);
	ft_putstr(buffer);
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
	return (0);
}
