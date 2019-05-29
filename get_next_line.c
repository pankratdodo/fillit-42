/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:09:47 by plettie           #+#    #+#             */
/*   Updated: 2019/05/04 17:25:45 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int				ft_str_fd(char **str, char **line, int fd, int res)
{
	int			i;
	char		*src;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\0')
	{
		if (res == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		src = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = src;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*str[1025];
	char		*src;
	char		buff[BUFF_SIZE + 1];
	int			chten;

	if (fd < 0 || line == NULL || (read(fd, NULL, 0) < 0))
		return (-1);
	while ((chten = read(fd, buff, BUFF_SIZE)))
	{
		buff[chten] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		src = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = src;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (chten < 0)
		return (-1);
	else if (chten == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_str_fd(str, line, fd, chten));
}
