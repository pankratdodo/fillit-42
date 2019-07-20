/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/07/21 02:06:19 by caellis          ###   ########.fr       */
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
	int			flag;
	int			pos_to_fill[4];

	flag = 0;
	i = 0;
	while (i < 4)
	{
		x_ctl = map[pos].x + fig->shape[i].x;
		y_ctl = map[pos].y + fig->shape[i].y;
		if (x_ctl < 0 || x_ctl >= side || y_ctl < 0 || y_ctl >= side)	// выходит за пределы карты (О - здесь можно также делать проверку "может ли вообще поместиться"
		{
			flag = 1;
			break; // было return(0) - стало break + flag, также на строчке 76;
		}
		if (map[pos + fig->shape[i].x * side + fig->shape[i].y].ind != '.')
			return (0);
		else
			pos_to_fill[i] = pos + fig->shape[i].x * side + fig->shape[i].y;
		i++;
	}
	i = 0;
	while (!flag && i < 4)
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
	if (!figs || figs->index == (char)0)
	{
		ft_lstadd(&sols, ft_lstnew(map, sizeof(t_cell) * side * side + 1));
		return (1);
	}
	if (pos == side * side)
		return (0);
	if (!insert_figure(map, figs, pos, side))
		return (cracker(map, figs, sols, ++pos, side));
	return (cracker(map, figs->next, sols, pos, side));
}

t_cell		*solve_it(t_list *solutions, t_tetris *figures, int side)
{
	t_cell		*map;
	int			pos;

	pos = 0;
	MALL_CHECK(map = map_init(side));
	// нужно вставить сюда условия перезапуска cracker'а, чтобы не первое попавшееся решение брать (тем более с расширением карты, которое было не нужно)
	// кстати, в инсерте я одинаково реагирую как на выход за пределы ряда, так и на невозможность вставки
	if (!cracker(map, figures, solutions, pos, side))
	{
		free(map);
		return (solve_it(solutions, figures, ++side));
	}
	print_map(map, side);
	// Теперь нужно выбрать из всех решений самое пиздатое 
	// - у него должна быть наименьшая площадь и ширина занимаемых клеток
	return (map);
}
