/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:14:15 by sammeuss          #+#    #+#             */
/*   Updated: 2022/12/28 15:46:11 by sammeuss         ###   ########.fr       */
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

int	ft_strlen_backslash_n(char *s, int *read_size, int choice)
{
	int	i;

	i = 0;
	(void)read_size;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	if (choice == 1)
		if (i == ft_strlen(s))
			return (0);
	return (i);
}

char	*ft_fill_save(char *save, int *read_size)
{
	int		i;
	int		x;
	char	*new;

	new = NULL;
	x = 0;
	i = 0;
	if (!save)
		return (NULL);
	while (save[i])
	{
		if (save[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (save[i - 1] != '\n' && *read_size == 0)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	if (save[i - 1] == '\n')
		while (save[i])
			new[x++] = save[i++];
	else
	{
		while (save[x])
		{
			new[x] = save[x];
			x++;
		}
	}
	new[x] = 0;
	free(save);
	return (new);
}
