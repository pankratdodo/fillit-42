/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/06/27 13:12:41 by caellis          ###   ########.fr       */
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
	
	return (sqrt--);
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

t_cell		*solve_it(t_tetris **figures, char q)
{
	t_cell		*c_map;
	int			size;

	size = 8 * q;			// площадь оптимального оптимального решения <= этой (и >= 4 * q)
	c_map = map_init(size);	// Выдели среднюю необходимую карту_точек
	//print_out(cracker(&c_map, *figures, position, size, flag));							// Найди карту_точек и распечатай как норм карту
	return (c_map);
}
