/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredrika <fredrika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:54:38 by fredrika          #+#    #+#             */
/*   Updated: 2019/10/22 17:52:51 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(file) +
		ft_strlen(buf) + 1))))
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

char	*ft_cpyline(char **file, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	*temp;

	i = 0;
	while (file[fd] && file[fd][i] != '\n' && file[fd][i] != '\0')
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (file[fd] && file[fd][++i] != '\n' && file[fd][i] != '\0')
		line[i] = file[fd][i];
	line[i++] = '\0';
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(&file[fd][i])))))
		return (NULL);
	j = -1;
	while (file[fd] && file[fd][i + ++j] != '\0')
		temp[j] = file[fd][i + j];
	temp[j] = '\0';
	free(file[fd]);
	file[fd] = temp;
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 2];
	int			ret;
	static char	*file[1024];

	if (fd < 0 || line == NULL)
		return (-1);
	ret = 1;
	while (ft_fulline(file[fd]) == 0 && ret > 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		file[fd] = ft_strcat(file[fd], buf);
	}
	if (!(*line = ft_cpyline(file, fd)))
		return (-1);
	return (ret == 0 ? 0 : 1);
}
