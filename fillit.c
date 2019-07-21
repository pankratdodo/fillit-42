/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:09:49 by caellis           #+#    #+#             */
/*   Updated: 2019/07/21 04:08:18 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         main(int ac, char **av)
{
    int 		fd;
    char        error;
    char        q;
    char        *input;
	t_tetris	*figures;
	t_list		*solutions;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if ((q = is_valid(fd)))
    {
		close(fd);
        read(open(av[1], O_RDONLY), (input = malloc(547)), 547);
        ERR_ZERO(figures = map_2_figures(input, figures, q));
		print_figure(&figures);
		solve_it((solutions = NULL), figures, ez_sqrt(4 * q), 0);
        /*ft_strdel(&input);        //чисти input
        ft_tetris_delete(&figures); //чисти figures
	*/}
	else
        write(1, "sore ne valid\n", 14);
    close(fd);
    return (0);
}
