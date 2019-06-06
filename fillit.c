/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:09:49 by caellis           #+#    #+#             */
/*   Updated: 2019/06/06 18:49:19 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         main(int ac, char **av)
{
    int 		fd;
    char 		c;
	char		*c_map;
	t_tetris	*tetris;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open("test.txt", O_RDONLY);
    if (is_valid(fd, c_map))				// ПРОБЛЕМА : fd уже прочитан -> или {close(fd) ; open(test.txt)} по-новой
    {										//  ИЛИ сразу засовывать считанные знаки в с_map (выделяя память итд)
		write(1, "harosh\n", 7);              

	}
	else
        write(1, "sore ne valid\n", 14);      // Или еррор :(
    return (0);
}