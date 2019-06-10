/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:47:43 by caellis           #+#    #+#             */
/*   Updated: 2019/06/10 19:49:34 by caellis          ###   ########.fr       */
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
#include <stdio.h>

/*
** Основная структура
* Letter (a , B , C ...)
* Byte value of a figure
* Coordinates (high and low && x and y respectively)
*/

typedef struct		s_tetris
{
	char			index;
	unsigned short	shape;
	int				xl;
	int				xh;
	int				yl;
	int				yh;
	struct s_tetris	*next;
}					t_tetris;

t_tetris    *map_2_figures(char *map, t_tetris **figures, char q);
char        is_valid(int fd, char **map);
//char		solve_it(t_tetris **figures, char q);

#endif

#ifndef IS_VALID_H
# define IS_VALID_H

#include <fcntl.h>
#include <unistd.h>

#endif

#ifndef TETRIS_FUN_H
# define TETRIS_FUN_H

void		print_figure(t_tetris *fig);

#endif
