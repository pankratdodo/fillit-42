/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/07/15 17:16:40 by caellis          ###   ########.fr       */
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

t_cell		*solve_it(t_list *solutions, t_tetris *figures, int side)
{
	t_cell		*c_map;
	size_t		map_size;
	char		flag;
	char		pos;

	pos = 0;
	flag = -1;
	if (!figures)
	{
		// Значит мы уже все решили и надо только выбрать ответ
		// return (select_solution(solutions));
	}
	MALL_CHECK(c_map = map_init(side));	// Выдели среднюю необходимую карту_точек
	while (pos < (map_size = sizeof(t_cell) * side * side + 1))
	{
		
	}
	cracker(&c_map, figures, side, pos, &flag);
	ft_lstadd(&solutions, ft_lstnew(c_map, map_size));
	
	return (solve_it(solutions, figures, side + 1));
}
