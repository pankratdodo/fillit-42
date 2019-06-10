a/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:47:43 by caellis           #+#    #+#             */
/*   Updated: 2019/06/10 15:27:38 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** Хэдеры функций, используемых в fillit.c (это и есть наш main)
*/
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
/*
** Основная структура
*/
typedef	struct		s_tetris
{
	char			index;			// Letter (a , B , C ...)
	unsigned short	shape;			// Byte value of a figyre
	int				xh, xl, y1,y2;	// Coordinates (high and low && x and y respectively)
	s_tetris		*next;
}					t_tetris;

//t_tetris    *map_2_figures(char *map, t_tetris **figures, char q);
char        is_valid(int fd, char **map);
//char		solve_it(t_tetris **figures, char q);

#endif