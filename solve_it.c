/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/07/05 21:49:18 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
* return NULL on error or just print the damn answer
*/
t_cell		*cracker(t_cell **c_map, t_tetris *figures, int side, char &flag)
{
	//check if you can fit the map

	return (NULL);
}


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

t_cell		*solve_it(t_tetris **figures, int side, char pos)
{
	t_list		*crackers;
	t_cell		*c_map;
	size_t		map_size;
	char		flag;

	MALL_CHECK(c_map = map_init(side));	// Выдели среднюю необходимую карту_точек
	map_size = sizeof(t_cell) * side * side + 1;
	MALL_CHECK(crackers = ft_lstnew(c_map, map_size));
	cracker(&c_map, *figures, side, &flag);		// Найди карту_точек и распечатай как норм карту
	return (c_map);
}
