/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:11:15 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/17 11:51:34 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static int	i = 0;
	int			j;
	int			ret;

	if (buf[i] == '\0')
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret <= 0)
			return ret == 0 ? (0) : (-1);
		buf[ret + 1] = '\0';
		j = 0;
		while (buf[i + j] != '\n' && buf[i + j])
			j++;
		if (!(*line = (char *)malloc(sizeof(char) * (j + 1))))
			return (-1);
		j = 0;
		while (buf[i] != '\n' && buf[i])
			*line[j++] = buf[i++];
		if (buf[i++] == '\n')
		{
			*line[j + 1] = '\0';
			return (1);
		}
	}
	return (0);
}

int		main(int ar, char **av)
{
	(void)ar;
	int		fd;
	char	*line;

	if ((fd = open(av[1], O_RDONLY)))
		return (-1);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}
