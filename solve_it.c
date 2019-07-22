/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/07/23 01:55:35 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*can_insert(t_cell *map, t_tetris *fig, int *pos_to_fill, int pos)
{
	int			i;
	int			x_ctl;
	int			y_ctl;
	int			cur_pos;
	char		side;

	i = 0;
	side = map->side;
	if (pos >= side * side) // условие выхода из рекурсии
		return (NULL);
	if (!pos_to_fill)
		pos_to_fill = (int *)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		x_ctl = map[pos].x + fig->shape[i].x;
		y_ctl = map[pos].y + fig->shape[i].y;
		cur_pos = pos + fig->shape[i].x * side + fig->shape[i].y;
		if (x_ctl < 0 || x_ctl >= side || y_ctl < 0 || y_ctl >= side)	// выходит за пределы карты (О - здесь можно также делать проверку "может ли вообще поместиться"
			return (can_insert(map, fig, pos_to_fill, ++pos));	// было return(0) - стало + рекурсивный вызов от следующей позиции;
		else if (map[cur_pos].ind != '.')
			return (can_insert(map, fig, pos_to_fill, ++pos));	// уже стоит фигура был  return(0) -> может быть попробовать рекурсивный вызов от следующей позиции?
		else
			pos_to_fill[i] = cur_pos;
		i++;
	}
	return (pos_to_fill);
}

void	insert_figure(t_cell *map, t_tetris *fig, int *pos_to_fill)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		map[pos_to_fill[i]].ind = fig->index;
		i++;
	}
}

void	clean_figure(t_cell *map, int *pos_to_fill)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		map[pos_to_fill[i]].ind = '.';
		i++;
	}
}

int		cracker(t_cell *map, t_tetris *figures)
{
	int		pos;
	int		*points;

	pos = 0;
	if (figures->index == 0)
		return (1);
	while ((points = can_insert(map, figures, NULL, pos)))
	{
		insert_figure(map, figures, points);
		if (cracker(map, figures->next))
			return (1);
		clean_figure(map, points);
		pos++;
	}
	return (0);
}

t_cell	*solve_it(t_tetris *figures, char side)
{
	t_cell		*map;
	int			pos;

	ERR_ZERO(map = map_init(side));
	pos = 0;
	if (!cracker(map, figures))
	{
		free(map);
		return (solve_it(figures, ++side));
	}
	return (map);
}
