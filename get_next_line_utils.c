/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:14:15 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/14 21:58:57 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_backslash_n(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_fill_save(char *save, char *buffer, int len_buff, char *line)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	free(save);
	save = malloc(sizeof(char) * (len_buff - ft_strlen(line)));
	if (!save)
		return (0);
	while (buffer[i - 1] != '\n')
			i++;
	while (buffer[x])
	{
		save[x] = buffer[i];
		i++;
		x++;
	}
	return (save);
}

// char	*check_read(char *buffer)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	if (!buffer)
// 		return (0);
// 	while (buffer[i] != '\0')
// 		i++;
// 	str = malloc(sizeof(char) * i + 1);
// 	i = 0;
// 	while (buffer[i] != '\0')
// 	{
// 		str[i] = buffer[i];
// 		i++;
// 	}
// 	return (str);
// }