/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:13:41 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/16 16:26:36 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, int *read_size)
{
	char	*r;
	int		i;
	int		x;
	int		diff;

	diff = 0;
	x = 0;
	i = 0;
	r = malloc(sizeof(char) * (ft_strlen(s1) + (*read_size) + 1));
	if (!r)
		return (NULL);
	// if (ft_strlen(r) > (*read_size))
	// {
	// 	diff = ft_strlen(r) - (*read_size);
	// 	free(r)
	// 	r = malloc(sizeof(char) * (ft))
	// }
	if (s1)
	{
		while (s1[i])
		{
			r[i] = s1[i];
			i++;
		}
	}
	while (x < (*read_size))
	{
		r[i] = s2[x];
		i++;
		x++;
	}
	r[i] = 0;
	return (r);
}

char	*ft_read_until_backslash_n(char	*s, int fd, char *save, int *read_size)
{
	int		u;

	u = 0;
	*read_size = read(fd, s, BUFFERSIZE);
	if (*read_size == 0)
		return (save);
	while (u <= (*read_size))
	{
		if (u == (*read_size))
		{
			save = ft_strjoin(save, s, read_size);
			*read_size = read(fd, s, BUFFERSIZE);
			u = 0;
		}
		else if (s[u] == '\n')
		{
			save = ft_strjoin(save, s, read_size);
			return (save);
		}
		u++;
	}
	return (save);
}

char	*ft_last_line(char	*line, char	*save, int	*read_size)
{
	line = malloc(sizeof(char) * ft_strlen(save) + 1);
		if (!line)
			return (0);
		while (save[i])
		{
			line[i] = save[i];
			return (line);
			i++;
		}
		line[i + 1] = 0;
}
char	*ft_line(char *save, char *line, int *read_size)
{
	int	i;

	i = 0;
	if (*read_size == 0)
		ft_last_line(line, save, &read_size);
	line = malloc(sizeof(char) * ft_strlen_backslash_n(save, read_size) + 1);
	if (!line)
		return (0);
	while (save[i])
	{
		line[i] = save[i];
		if (save[i] == '\n')
		{
			line[i] = save[i];
			line[i + 1] = '\0';
			return (line);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFERSIZE + 1];
	static char	*save;
	char		*line;
	int			read_size;

	read_size = 0;
	buffer[BUFFERSIZE] = 0;
	line = NULL;
	if (fd < 0 || BUFFERSIZE < 1 || read(fd, buffer, 0) < 0)
		return (0); 
	if (ft_strlen_backslash_n(save, &read_size) > 0)
	{
		line = ft_line(save, line, &read_size);
		save = ft_fill_save(save);
		return (line);
	}
	save = ft_read_until_backslash_n(buffer, fd, save, &read_size);
	line = ft_line(save, line, &read_size);
	save = ft_fill_save(save);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("test.txt", O_RDONLY);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	close(fd);
	return (0);
}
