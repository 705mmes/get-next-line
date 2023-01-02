/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:00:28 by sammeuss          #+#    #+#             */
/*   Updated: 2023/01/02 15:49:04 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("read_error.txt", O_RDONLY);
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