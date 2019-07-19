/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/07/20 00:30:32 by caellis          ###   ########.fr       */
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
	int			x_ctl;
	int			y_ctl;
	int			flag;
	int			pos_to_fill[4];

	flag = 0;
	if (pos == side * side)
		return (0);
	fig = *figs;
	while (fig->index != (char)0)
	{
		i = 0;
		while (i < 4)
		{
			x_ctl = map[pos].x + fig->shape[i].x;
			y_ctl = map[pos].y + fig->shape[i].y;
			if (x_ctl < 0 || x_ctl >= side || y_ctl < 0 || y_ctl >= side)
				return (insert_figure(map, figs, ++pos, side));
			if (map[pos + fig->shape[i].x * side + fig->shape[i].y].ind != 0)
				return (insert_figure(map, figs, ++pos, side));
			else
				pos_to_fill[i] = pos + fig->shape[i].x * side + fig->shape[i].y;
			i++;
		}
		i = 0;
		while (i < 4)
		{
			map[pos_to_fill[i]].ind = fig->index;
			i++;
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
	return (cracker(map, figs, sols, pos, side));
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
