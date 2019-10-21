/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:11:15 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/19 16:48:28 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 2];
	int		ret;
	int		flag;

	ret = 0;
	flag = 0;
	while (flag == 0)
	{
		flag = ft_create_str(buf, line, ret);
		if (flag == 1)
			return (1);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			return (ret);
		else if (ret != BUFFER_SIZE && buf[ret - 1] != '\n')
		{
			buf[ret] = '\n';
			buf[ret + 1] = '\0';
		}
		else
			buf[ret] = '\0';
	}
	return (1);
}

int		main(int ar, char **av)
{
	(void)ar;
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		printf("%s\n", line);
	close(fd);
	return (0);
}
