/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:41:22 by caellis           #+#    #+#             */
/*   Updated: 2019/06/26 18:08:27 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
* return NULL on error or just print the damn answer
*/
void		solve_it(t_tetris *figures, char q)
{
	t_cell		*c_map;
	
	MALL_CHECK(c_map = (t_cell *)malloc(sizeof(t_cell) * 8 * q));	// Выдели минимальную карту_точек (8 * q)
	print_out(cracker(&c_map, figures));								// Найди карту_точек и распечатай как норм карту
}
