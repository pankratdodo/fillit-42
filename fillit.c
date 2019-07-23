/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:09:49 by caellis           #+#    #+#             */
/*   Updated: 2019/07/23 16:40:23 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	int			fd;
	char		q;
	char		*input;
	t_tetris	*figures;
	t_cell		*map;

	figures = NULL;
	if (ac != 2 || (fd = open(av[1], O_RDONLY)) <= 0)
	{
		ft_putstr_fd("usage: fillit file_with_map\n", 2);
		return (0);
	}
	if (ac == 2 && (q = is_valid(fd)))
	{
		close(fd);
		read(open(av[1], O_RDONLY), (input = malloc(547)), 547);
		ERR_ZERO(figures = map_2_figures(input, figures, q));
		map = solve_it(figures, ez_sqrt(4 * q));
		print_map(map, map->side);
		cleaner(&figures, &map, &input);
	}
	else
		ft_putstr("error\n");
	close(fd);
	return (0);
}
