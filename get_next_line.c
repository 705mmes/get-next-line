/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:13:41 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/14 21:59:08 by sammeuss         ###   ########.fr       */
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
	while (s2[x])
	{
		r[i] = s2[x];
		i++;
		x++;
	}
	r[i] = 0; // Ajout du \0 a la fin du join 
	return (r);
}

char	*ft_read_until_backslash_n(char	*s, int fd, char *save, int *len_buff)
{
	int		u;

	u = -1;
	read(fd, s, BUFFERSIZE);
	// s = check_read(s);
	while (++u <= (*len_buff))
	{
		// if (save[ft_strlen(save)] == '\n')
		// 	return (save);
		if (u == (*len_buff))
		{
			save = ft_strjoin(save, s);
			read(fd, s, BUFFERSIZE);
			// s = check_read(s);
			(*len_buff) += ft_strlen(s);
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
	int			len_buff;

	len_buff = 0;
	 buffer[BUFFERSIZE] = 0;
	// buffer = malloc(sizeof(char) * BUFFERSIZE);
	// if (!buffer)
	// 	return (0);
	// read(fd, buffer, BUFFERSIZE);
	// len_buff += ft_strlen(buffer);
	len_buff += BUFFERSIZE;
	save = ft_read_until_backslash_n(buffer, fd, save, &len_buff);
	line = malloc(sizeof(char) * ft_strlen_backslash_n(save) + 1); // Malloc pas assez pour le \0 a la fin de line
	if (!line)
		return (0);
	line = ft_line(save, line); // Doit ajouter un \0 a la fin
	//free(save);
	save = ft_fill_save(save, buffer, len_buff, line); // free save dans cette fonction, si il est free avant on peux pas remplir la save avec ce qu'il y a apres le \n
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
	// buffer = get_next_line(fd);
	// printf("%s", buffer);
	// buffer = get_next_line(fd);
	// printf("%s", buffer);
	close(fd);
	return (0);
}
