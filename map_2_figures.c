/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:08:15 by caellis           #+#    #+#             */
/*   Updated: 2019/06/20 15:54:51 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris    *map_2_figures(char const *map, t_tetris **figures, char q)
{
	char		*s_fig;
	char		index;
	char		i;
	int			p_num;
	t_point		*shape;

	MALL_CHECK(shape = (t_point *)malloc(sizeof(t_point) * 4));
	index = 'A';
	while (index++ < 'A' + q)
	{
		i = 0;
		while (i < 21)
		{
			p_num = 0;
			if (map[i] == '#')
				abs_point_2_shape(&shape, p_num, i / 5, i % 5);
			i++;
		}
		shape = set_shape(&shape);
		add_figure(figures, new_figure(index, shape));
		if (index != 'A' + q)
			map += 22;
	}
	return (*figures);
}