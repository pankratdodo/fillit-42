/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/07/19 18:01:59 by caellis          ###   ########.fr       */
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

int		insert_figure(t_cell *map, t_tetris **figs, int pos, int side)
{
	int			i;
	t_tetris	*fig;

	fig = *figs;
	while (fig->index != (char)0)
	{
		while (i < 4)
		{
			
		}
		fig = fig->next;
	}
	return (1);
}

int		cracker(t_cell *map, t_tetris *figs, t_list *sols, int pos, int side)
{
	if (!figs || figs->index == (char)0)
	{
		ft_lstadd(&sols, ft_lstnew(map, sizeof(t_cell) * side * side + 1));
		return (1);
	}
	if (pos == side * side)
		return (0);
	if (!insert_figure(map, &figs, pos, side))
		return (cracker(map, figs, sols, ++pos, side));
	cracker(map, figs, sols, pos, side);
}

t_cell		*solve_it(t_list *solutions, t_tetris *figures, int side)
{
	t_cell		*map;
	int			pos;

	pos = 0;
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
