/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:11:15 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/17 13:03:30 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft__strcat(char *str, char *buf)
{
	if (str == NULL)
	{
		if (!())
	}
}

int		ft_create_str(char *buf, char **line)
{
	const char	*str = NULL;
	int			i;

	str = ft_strcat(str, buf);
	if (ft_fulline(str))
	{
		*line = ft_cpyline;\
		str = NULL;
		return (1);
	}
	else
		return (0);
}


int		get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		flag;
	int		ret;

	flag = 0;
	while (flag = 0)
	{
		if (!(ret = read(fd, buf, BUFFER_SIZE)))
			return (-1);
		if (ret == 0)
			return (0);
		buf[ret + 1] = '\0';
		flag = ft_create_str(buf, line);
	}
	return (1);
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

/*
read into buffer, if -1 return -1, if 0 print ev existing str return 0
cpy into new string, if no \n, redo reading and append until str contains \n,
					if \n substr into line, set string to remaining part return 1
*/
