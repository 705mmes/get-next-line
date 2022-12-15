/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:14:15 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/15 16:42:00 by smunio           ###   ########.fr       */
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

int	ft_strlen_backslash_n(char *s, int *read_size)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (i == ft_strlen(s) && (*read_size) < BUFFERSIZE)
		return (0);
	return (i);
}

char	*ft_fill_save(char *save)
{
	int		i;
	int		x;
	char	*new;

	x = 0;
	i = 0;
	while (save[i - 1] != '\n')
			i++;
	new = malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	while (save[i])
	{
		new[x] = save[i];
		i++;
		x++;
	}
	new[x] = 0;
	free(save);
	return (new);
}
