/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:08:15 by caellis           #+#    #+#             */
/*   Updated: 2019/07/23 14:47:41 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*map_2_figures(char const *map, t_tetris *figures, char q)
{
	char		index;
	char		i;
	int			p_num;
	t_point		*shape;

	index = 'A';
	MALL_CHECK(shape = (t_point *)malloc(sizeof(t_point) * 4));
	while (index < 'A' + q)
	{
		i = -1;
		p_num = 0;
		while (++i < 21)
			if (*(map + i) == '#')
				abs_point_2_shape(&shape, p_num++, i / 5, i % 5);
		shape = set_shape(&shape);
		add_figure(&figures, new_figure(index, q, shape));
		index++;
		map += 21;
	}
	add_figure(&figures, new_figure((char)0, q, shape));
	free(shape);
	return (figures);
}

void			print_map(t_cell *c_map, char side)
{
	int			i;

	i = 0;
	while (i < side * side)
	{
		if (i != 0 && i % side == 0)
			ft_putchar('\n');
		ft_putchar(c_map[i].ind);
		i++;
	}
	ft_putchar('\n');
}

t_cell			*map_init(char side)
{
	t_cell		*c_map;
	int			i;

	i = 0;
	MALL_CHECK(c_map = (t_cell *)malloc(sizeof(t_cell) * side * side));
	while (i < side * side)
	{
		c_map[i].x = i / side;
		c_map[i].y = i % side;
		c_map[i].ind = '.';
		c_map[i].side = side;
		i++;
	}
	return (c_map);
}
