/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredrika <fredrika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:54:38 by fredrika          #+#    #+#             */
/*   Updated: 2019/10/22 10:43:19 by fredrikalindh    ###   ########.fr       */
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
	int		j;

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

char	*ft_cpyline(char *file)
{
	int		i;
	char 	*line;

	i = 0;
	while (file[i] != '\n' && file[i])
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (file[++i] != '\n' && file[i])
		line[i] =  file[i];
	line[i] = '\0';
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*file[1024];

	if (fd < 0 || line == NULL)
		return (-1);
	file[fd] == NULL;
	ret = 1;
	while (ft_fulline(file[fd]) == 0 && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			return (ret);
		file[fd] = ft_strcat(file[fd], buf);
	}
	*line = ft_cpyline(file[fd]);
	return (1);
}
