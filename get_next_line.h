/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:03:41 by plettie           #+#    #+#             */
/*   Updated: 2019/05/07 17:37:48 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 1

int		get_next_line(int const fd, char **line);
int		ft_str_fd(char **str, char **line, int fd, int ret);

#endif
