/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/07/19 11:23:12 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
* return NULL on error or just print the damn answer
*/

t_cell		*map_init(int side)
{
	t_cell		*c_map;
	int			i;

	i = 0;
	MALL_CHECK(c_map = (t_cell *)malloc(sizeof(t_cell) * side * side + 1));
	while (i < side * side + 1)
	{
		c_map[i].x = i / side;
		c_map[i].y = i % side;
		c_map[i].ind = 0;
		i++;
	}
	return (c_map);
}

int		cracker(t_cell *map, t_tetris *figs, t_list *sols, int pos, int side)
{
	int		x;
	int		y;

	if (!figs)
	{
		
		return (1);
	}
	while (figs->next)
	{
		if (insert_figure(map, figs))//попробуй вставить 

	}
}

t_cell		*solve_it(t_list *solutions, t_tetris *figures, int side)
{
	t_cell		*map;
	int			pos;

	MALL_CHECK(map = map_init(side));
	if (!cracker(map, figures, solutions, pos, side))
	{
		free(map);
		return (solve_it(solutions, figures, ++side));
	}
	// Теперь нужно выбрать из всех решений самое пиздатое 
	// - у него должна быть наименьшая площадь и ширина занимаемых клеток
	return (map);
}
