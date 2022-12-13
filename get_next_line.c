/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:13:41 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/10 22:34:03 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!s1)
		s1 = "";
	r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!r)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[x] && s2[x] != '\n')
	{
		r[i] = s2[x];
		i++;
		x++;
	}
	if (s2[i + 1] == '\n')
		r[i + 1] = '\n';
	return (r);
}

char	*ft_read_until_backslash_n(char	*s, int fd, char *save)
{
	int	u;

	u = -1;
	while (++u <= BUFFERSIZE)
	{	
		// if (save[ft_strlen(save)] == '\n')
		// 	return (save);
		if (u == BUFFERSIZE)
		{
			save = ft_strjoin(save, s);
			read(fd, s, BUFFERSIZE);
			u = -1;
		}
		else if (s[u] == '\n')
		{
			save = ft_strjoin(save, s);
			return (save);
		}
	}
	return (save);
}

char	*ft_line(char *save, char *line)
{
	int	i;

	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		if (save[i] == '\n')
		{
			line[i] = save[i];
			return (line);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;
	char		*line;

	buffer = malloc(sizeof(char) * BUFFERSIZE);
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFERSIZE);
	save = ft_read_until_backslash_n(buffer, fd, save);
	line = malloc(sizeof(char) * ft_strlen_backslash_n(save));
	line = ft_line(save, line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("test.txt", O_RDONLY);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	// buffer = get_next_line(fd);
	// printf("%s", buffer);
	// buffer = get_next_line(fd);
	// printf("%s", buffer);
	// buffer = get_next_line(fd);
	// printf("%s", buffer);
	// buffer = get_next_line(fd);
	// printf("%s", buffer);
	close(fd);
	return (0);
}