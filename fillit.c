/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:09:49 by caellis           #+#    #+#             */
/*   Updated: 2019/06/10 15:14:37 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         main(int ac, char **av)
{
    int 		fd;
    char        q;
	char		*map;
	t_tetris	*figures;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if ((q = is_valid(fd, &map)))
    {
		write(1, "harosh\n", 7);
		figures = map_2_figures(map, &figures, q);	// Получаем массив фигурок или ошибку
	}
	else
        write(1, "sore ne valid\n", 14);      		// Или еррор :(
    return (0);
}
