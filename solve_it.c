/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/06/27 13:47:06 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
* return NULL on error or just print the damn answer
*/
t_cell		*cracker(t_cell **c_map, t_tetris *figures)
{
	//check if you can fit the map
}

int			ez_sqrt(int x)
{
	int		sqrt;

	sqrt = 1;
	while (sqrt * sqrt < x)
		sqrt++;
	if (x / sqrt != sqrt)
		sqrt =  sqrt * ez_sqrt(sqrt);
	return (sqrt);
}

t_cell		*map_init(int size)
{
	t_cell		*c_map;
	int			i;

	i = 0;
	MALL_CHECK(c_map = (t_cell *)malloc(sizeof(t_cell) * size + 1));
	while (i <= size)
	{
		c_map[i].x = i / ez_sqrt(size);
		c_map[i].y = i % ez_sqrt(size);
		c_map[i].ind = 0;
		i++;
	}
	return (c_map);
}

t_cell		*solve_it(t_tetris **figures, int size, char pos)
{
	t_cell		*c_map;

	MALL_CHECK(c_map = map_init(size));	// Выдели среднюю необходимую карту_точек
	cracker(&c_map, *figures, pos, size, flag);							// Найди карту_точек и распечатай как норм карту
	return (c_map);
}
