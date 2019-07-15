/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:09:49 by caellis           #+#    #+#             */
/*   Updated: 2019/07/15 16:32:09 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         main(int ac, char **av)
{
    int 		fd;
    char        error;
    char        q;
    char        *test_map;  // Временная переменная для карты
	t_tetris	*figures;
	t_list		*solutions;
	t_cell		*solution;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if ((q = is_valid(fd)))
    {
		close(fd);
        read(open(av[1], O_RDONLY), (test_map = malloc(547)), 547);
        ERR_ZERO(figures = map_2_figures(test_map, figures, 10));			// Вставить q вместо 10	
		print_figure(&figures);												// удалить 
		ERR_ZERO(solution = solve_it((solutions = NULL), figures, ez_sqrt(4 * q)));	// Получаем еррор ИЛИ ответ; площадь оптимального оптимального решения >= 4 * q
        /*ft_strdel(&map);                                        // Большая этническая чистка мусора (map + figures)
        ft_tetris_delete(&figures);
	*/}
	else
        write(1, "sore ne valid\n", 14);      		            // Или еррор :(
    close(fd);
    return (0);
}
