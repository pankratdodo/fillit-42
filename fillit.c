/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:09:49 by caellis           #+#    #+#             */
/*   Updated: 2019/06/09 13:29:35 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         main(int ac, char **av)
{
    int 		fd;
    char 		c;
	char		*map;
	t_tetris	*figures;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open("test.txt", O_RDONLY);
    if ((map = is_valid(fd)))
    {
		write(1, "harosh\n", 7);
		//figures = map_2_figures(map, figures);	// Получаем массив фигурок или ошибку
	}
	else
        write(1, "sore ne valid\n", 14);      		// Или еррор :(
    return (0);
}