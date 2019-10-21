/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:09:36 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/20 11:57:38 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
# endif

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_rest(char *str);
char	*ft_strcat(char *str, char *buf);
int		ft_fulline(char *str);
char	*ft_cpyline(char *str);
int		ft_create_str(char *buf, char **line, int ret);

#endif
