/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/07/24 15:33:22 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*can_insert(t_cell *map, t_tetris *fig, int pos)
{
	int			i;
	int			x_ctl;
	int			y_ctl;
	int			cur_pos;
	int			*points;

	i = -1;
	if (pos >= map->side * map->side)
		return (NULL);
	MALL_CHECK(points = (int *)malloc(sizeof(int) * 4));
	while (++i < 4)
	{
		x_ctl = map[pos].x + fig->shape[i].x;
		y_ctl = map[pos].y + fig->shape[i].y;
		cur_pos = pos + fig->shape[i].x * map->side + fig->shape[i].y;
		if (x_ctl < 0 || x_ctl >= map->side || y_ctl < 0 ||\
			y_ctl >= map->side || map[cur_pos].ind != '.')
		{
			free(points);
			return (can_insert(map, fig, ++pos));
		}
		else
			points[i] = cur_pos;
	}
	return (points);
}

static void		insert_figure(t_cell *map, t_tetris *fig, int *pos_to_fill)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		map[pos_to_fill[i]].ind = fig->index;
		i++;
	}
}

static void		clean_figure(t_cell *map, int *pos_to_fill)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		map[pos_to_fill[i]].ind = '.';
		i++;
	}
}

static int		cracker(t_cell *map, t_tetris *figures)
{
	int			pos;
	int			*points;

	pos = 0;
	if (figures->index == 0)
		return (1);
	while ((points = can_insert(map, figures, pos)))
	{
		insert_figure(map, figures, points);
		if (cracker(map, figures->next))
		{
			free(points);
			return (1);
		}
		clean_figure(map, points);
		pos = points[0] + 1;
		free(points);
	}
	return (0);
}

t_cell			*solve_it(t_tetris *figures, char side)
{
	t_cell		*map;
	int			pos;

	MALL_CHECK(map = map_init(side));
	pos = 0;
	if (!cracker(map, figures))
	{
		free(map);
		return (solve_it(figures, ++side));
	}
	return (map);
}
