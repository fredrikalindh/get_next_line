/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredrika <fredrika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:54:38 by fredrika          #+#    #+#             */
/*   Updated: 2019/10/24 15:09:33 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str != NULL && str[i])
		i++;
	return (i + 1);
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

	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(file) +
		ft_strlen(buf) + 2))))
		return (NULL);
	i = 0;
	while (file != NULL && file[i])
	{
		new[i] = file[i];
		i++;
	}
	if (file != NULL)
		free(file);
	while (buf != NULL && *buf != '\0')
		new[i++] = *buf++;
	new[i] = '\0';
	return (new);
}

char	*ft_cpyline(char **file, int fd, int i, int ret)
{
	int		j;
	char	*line;
	char	*temp;

	while (file[fd] && file[fd][i] != '\n' && file[fd][i] != '\0')
		i++;
	if (((j = 0) == 0 && ret == 0 && i == 0) || file[fd] == NULL ||
	!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (file[fd] && file[fd][++i] != '\n' && file[fd][i] != '\0')
		line[i] = file[fd][i];
	line[i] = '\0';
	j = 0;
	if ((temp = NULL) == NULL && file[fd] && file[fd][i++] != '\0')
	{
		if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(&file[fd][i])))))
			return (NULL);
		while (file[fd][i] != '\0')
			temp[j++] = file[fd][i++];
		temp[j] = '\0';
	}
	free(file[fd]);
	file[fd] = temp;
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
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
	*line = ft_cpyline(file, fd, 0, ret);
	return (*line == NULL ? 0 : 1);
}
