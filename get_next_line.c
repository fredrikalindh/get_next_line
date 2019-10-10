/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:11:15 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/10 15:31:10 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	void	buf[BUFFER_SIZE + 1];
	static int i;
	int			j;

	i = 0;
	j = 0;
	if (read(fd, buf, BUFFER_SIZE) == -1)
		return (-1);
	buf[BUFFER_SIZE + 1] = '\0';
	while (buf[i] != '\n' && buf[i])
	{
		*line[j] = buf[i];
		j++;
		i++;
	}
	if (j == 0)
		return (0);
	else
	{
		*line[j] = '\0';
		i++;
		return (1);
	}
}
