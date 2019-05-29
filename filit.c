/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:07:11 by plettie           #+#    #+#             */
/*   Updated: 2019/05/27 17:07:12 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
int main(int ac, char **av)
{
    int fd;
    char **line;

    if (ac != 2)
        return (-1);
    if ((fd = open(av[1], O_RDWR)) < 0)
        return (-1);
    get_next_line(fd, line);
    is_valid(line);
    return (0);
}