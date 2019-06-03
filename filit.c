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

# define BUF_SIZE 1

char get_figure(int fd)
{
    char c[20];
    int n;
    
    if (fd < 0 || (read(fd, NULL, 0) < 0))
		return (0);
    if (!(n = read(fd, c, 20)))
        return (0);
    return (c);
}

int ft_error(int r)
{
    if (r == -1)
        write (1, "error\n", 6);
    exit(0);
}


int isNeighbor(char **figa, int x, int y)
{

}
int isValid(int fd)
{

    char c;
    char bc;
    int nb;

    nb = 0;
    while ((c = get_char(fd)))
    {
        if (!ft_strchr(".#\n", c))
            return (0);
        if (c == '\n')
        {
            if (c == bc)
            {
                if (nb != 16)
                    return (0);
                nb = 0;
            }
        }
        else
            nb++;
        bc = c;
    }
    
    return (1);
}

int main(int ac, char **av)
{
    int fd;
    char c;

    
    // if (ac != 2)
    // {
    //     write(1, "usage", 5);
    //     return (0);
    // }
    fd = open("test.txt", O_RDONLY);
    if (!isValid(fd))
    {
        printf("erorr");
    }
    // if (get_char(fd, &line) == -1 || (is_valid(&line) == -1))
    //     return (ft_error(-1));
    // //    printf("%s\n", line);
    return (0);
}