/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:47:43 by caellis           #+#    #+#             */
/*   Updated: 2019/06/26 14:15:55 by caellis          ###   ########.fr       */
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
** Основные структуры
*/
typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tetris
{
	char			index;		// Letter
	t_point			*shape;		// Array of 4 figure points in relative form (e.g. the first point is [x == 0 && y == 0]) 
	struct s_tetris	*next;
}					t_tetris;

# define MALL_CHECK(x) if (!(x)) return (NULL)
# define ERR_ZERO(x) if (!(x)) return (0)

t_tetris    		*map_2_figures(char const *map, t_tetris *figures, char q);
char        		is_valid(int fd, char **map);
//char				solve_it(t_tetris **figures, char q);

#endif

#ifndef IS_VALID_H
# define IS_VALID_H

#include <fcntl.h>
#include <unistd.h>

#endif

#ifndef TETRIS_FUN_H
# define TETRIS_FUN_H

void				print_figure(t_tetris **figures);
t_tetris			*new_figure(char i, t_point *shape);
void				add_figure(t_tetris **figs, t_tetris *new);
void				abs_point_2_shape(t_point **shape, int p_num, int x, int y);
t_point				*set_shape(t_point **shape);

#endif
