/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:09:49 by caellis           #+#    #+#             */
/*   Updated: 2019/06/19 17:09:28 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         main(int ac, char **av)
{
    int 		fd;
    char        error;
    char        q;
	char		*map;
	t_tetris	*figures;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if (1/* (q = is_valid(fd, &map)) */)                        // Закоменчено до исправления ошибок
    {
		ERR_ZERO(figures = map_2_figures(map, &figures, q));    // Получаем массив фигурок Или еррор :(		
		print_figure(figures);
		/* ERR_ZERO(!solve_it(&figures, q));                       // Получаем еррор ИЛИ печатаем ответ
        ft_strdel(&map);                                        // Большая этническая чистка мусора (map + figures)
        ft_tetris_delete(&figures);
	*/}
	else
        write(1, "sore ne valid\n", 14);      		            // Или еррор :(
    close(fd);
    return (0);
}
