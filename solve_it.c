/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/07/21 04:44:49 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
* return NULL on error or just print the damn answer
*/

void	print_map(t_cell *c_map, int side)
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

t_cell		*map_init(int side)
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
		i++;
	}
	return (c_map);
}

int		insert_figure(t_cell *map, t_tetris *fig, int pos, int side)
{
	int			i;
	int			x_ctl;
	int			y_ctl;
	int			pos_to_fill[4];
	int			cur_pos;

	i = 0;
	if (pos >= side * side) // условие выхода из рекурсии
		return (0);
	while (i < 4)
	{
		x_ctl = map[pos].x + fig->shape[i].x;
		y_ctl = map[pos].y + fig->shape[i].y;
		cur_pos = pos + fig->shape[i].x * side + fig->shape[i].y;
		if (x_ctl < 0 || x_ctl >= side || y_ctl < 0 || y_ctl >= side)	// выходит за пределы карты (О - здесь можно также делать проверку "может ли вообще поместиться"
			return (insert_figure(map, fig, ++pos, side));	// было return(0) - стало + рекурсивный вызов от следующей позиции;
		else if (map[cur_pos].ind != '.')
			return (insert_figure(map, fig, ++pos, side));	// уже стоит фигура был  return(0) -> может быть попробовать рекурсивный вызов от следующей позиции?
		else
			pos_to_fill[i] = cur_pos;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		map[pos_to_fill[i]].ind = fig->index;
		i++;
	}
	return (1);
}

int		cracker(t_cell *map, t_tetris *figs, t_list *sols, int pos, int side)
{
	int			i;
	static char		flag;
	
	print_map(map, side);		// for debugging
	ft_putstr("\n\n");
	if (pos >= side * side) // условие выхода из рекурсии
		return (0);
	if (!figs || figs->index == (char)0)
		return (1);
	if (!insert_figure(map, figs, pos, side))
		return (0);
	return (cracker(map, figs->next, sols, pos, side));
}

int		solve_it(t_list *solutions, t_tetris *figures, int side, int pos)
{
	t_cell		*map;

	ERR_ZERO(map = map_init(side));
	// нужно вставить сюда условия перезапуска cracker'а, чтобы не первое попавшееся решение брать (тем более с расширением карты, которое было не нужно)
	
	// кстати, в инсерте я одинаково реагирую как на выход за пределы ряда, так и на невозможность вставки
	if (!cracker(map, figures, solutions, pos, side))
	{
		free(map);
		return (solve_it(solutions, figures, ++side, pos));
	}
	ft_lstadd(&solutions, ft_lstnew(map, sizeof(t_cell) * side * side + 1));
	ft_putstr("This should be the result:\n");
	print_map(map, side);
	// Теперь нужно выбрать из всех решений самое пиздатое 
	// - у него должна быть наименьшая площадь и ширина занимаемых клеток
	return (1);
}
