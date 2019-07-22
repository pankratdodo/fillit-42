/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:47:43 by caellis           #+#    #+#             */
/*   Updated: 2019/07/22 15:58:10 by caellis          ###   ########.fr       */
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
	char			number;
	t_point			*shape;		// Array of 4 figure points in relative form (e.g. the first point is [x == 0 && y == 0]) 
	struct s_tetris	*next;
}					t_tetris;

typedef struct		s_cell
{
	char			x;
	char			y;
	char			ind;
	char			side;
}					t_cell;

# define MALL_CHECK(x) if (!(x)) return (NULL)
# define ERR_ZERO(x) if (!(x)) return (0)

t_tetris    *map_2_figures(char const *map, t_tetris *figures, char q);
char        is_valid(int fd);
t_cell		*solve_it(t_tetris *figures, char side);

#endif

#ifndef MAP_FUNCTIONS_H
# define MAP_FUNCTIONS_H

void		print_map(t_cell *c_map, char side);
t_cell		*map_init(char side);
#endif


#ifndef SOLVE_IT_H
# define SOLVE_IT_H

t_cell		*map_init(char size);
void		print_map(t_cell *c_map, char side);
#endif

#ifndef IS_VALID_H
# define IS_VALID_H

#include <fcntl.h>
#include <unistd.h>
#endif

#ifndef TETRIS_FUN_H
# define TETRIS_FUN_H

t_tetris			*new_figure(char i, char number, t_point *shape);
void				add_figure(t_tetris **figs, t_tetris *new);
void				abs_point_2_shape(t_point **shape, int p_num, int x, int y);
t_point				*set_shape(t_point **shape);
char				ez_sqrt(int x);
#endif
