/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:11:15 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/22 22:29:15 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_rest(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (str + 1);
		str++;
	}
	return (NULL);
}

char	*ft_strcat(char *str, char *buf)
{
	int		j;
	int		i;
	char	*new;

	j = -1;
	i = -1;
	if (str == NULL)
	{
		if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1))))
			return (NULL);
		while (buf != NULL && buf[++i] != '\0')
			new[i] = buf[i];
		new[i] = '\0';
	}
	else
	{
		if (!(new = (char *)malloc(sizeof(char) *
			(ft_strlen(buf) + ft_strlen(str) + 1))))
			return (NULL);
		while (str[++j])
			new[j] = str[j];
		while (buf[++i])
			new[j + i] = buf[i];
		new[i + j] = '\0';
	}
	return (new);
}

int		ft_fulline(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cpyline(char *str)
{
	int		i;
	char 	*line;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (str[++i] != '\n' && str[i])
		line[i] =  str[i];
	line[i] = '\0';
	return (line);
}

int		ft_create_str(char *buf, char **line, int ret)
{
	static char	*str = NULL;

	if (ret != 0)
		str = ft_strcat(str, buf);
	if (ft_fulline(str))
	{
		*line = ft_cpyline(str);
		str = ft_rest(str);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 2];
	int		ret;
	int		flag;

	ret = 0;
	flag = 0;
	if (fd < 0 || line == NULL)
		return (-1);
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

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	fd = open((argv[1]), O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		printf("|%s|\n", line);
	return (0);
}
