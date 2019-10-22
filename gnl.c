/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredrika <fredrika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:54:38 by fredrika          #+#    #+#             */
/*   Updated: 2019/10/22 11:43:00 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int		ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str != NULL && str[i])
		i++;
	return (i);
}

int		ft_fulline(char *file)
{
	while (file != NULL && *file != '\0')
	{
		if (*file == '\n')
			return (1);
		file++;
	}
	return (0);
}

char	*ft_strcat(char *file, char *buf)
{
	char	*new;
	int		i;

	i = -1;
	if (file == NULL)
	{
		if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1))))
			return (NULL);
		while (buf[++i])
			new[i] = buf[i];
		new[i] = '\0';
	}
	else
	{
		if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(file) + ft_strlen(buf) + 1))))
			return (NULL);
		while (file[++i])
			new[i] = file[i];
		free(file);
		while (buf && *buf)
			new[i++] = *buf++;
		new[i] = '\0';
	}
	return (new);
}

int		ft_cpyline(char *file, char **line)
{
	int		i;

	i = 0;
	while (file[i] != '\n' && file[i])
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	i = -1;
	while (file[++i] != '\n' && file[i])
		*line[i] =  file[i];
	*line[i] = '\0';
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*file[1024];

	if (fd < 0 || line == NULL)
		return (-1);
	ret = 1;
	while (ft_fulline(file[fd]) == 0 && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			return (ret);
		buf[ret] = '\0';
		file[fd] = ft_strcat(file[fd], buf);
	}
	return (ft_cpyline(file[fd], line)); // have to change what's left in a good way
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
