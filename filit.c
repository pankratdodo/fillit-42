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
#include <unistd.h>
#include "get_next_line.h"
#include "libft/libft.h"

int ft_error(int r)
{
    if (r == -1)
        write (1, "error\n", 6);
    exit(0);
}

int main(int ac, char **av)
{
    int fd;
    char *line;
    int v;
    int g;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open(av[1], O_RDWR);
    while ((g = get_next_line(fd, &line)) == 1)
        printf("%s\n", line);
    if ((g = get_next_line(fd, &line)) == -1 || (v = is_valid(&line)) == -1)
        return (ft_error(-1));
    //    printf("%s\n", line);
    return (0);
}