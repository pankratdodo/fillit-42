/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:09:49 by caellis           #+#    #+#             */
/*   Updated: 2019/06/27 13:47:04 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         main(int ac, char **av)
{
    int 		fd;
    char        error;
    char        q;
	char		*map;
    char        *test_map;  // Временная переменная для карты
	t_tetris	*figures;


    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    map = ft_strnew(1000);  
    if (1/*(q = is_valid(fd, &map))*/)                               // В map - лежит только последняя фигура
    {                                                           // поэтому я пока буду юзать test_map переменную
		close(fd);
        read(open(av[1], O_RDONLY), (test_map = malloc(547)), 547);
        ERR_ZERO(figures = map_2_figures(test_map, figures, 10));    // Получаем массив фигурок Или еррор :(		
		print_figure(&figures);
		/* ERR_ZERO(!solve_it(&figures, 2, 0));             // Получаем еррор ИЛИ печатаем ответ; площадь оптимального оптимального решения <= 8 * q (и >= 4 * q)
        ft_strdel(&map);                                        // Большая этническая чистка мусора (map + figures)
        ft_tetris_delete(&figures);
	*/}
	else
        write(1, "sore ne valid\n", 14);      		            // Или еррор :(
    close(fd);
    return (0);
}
