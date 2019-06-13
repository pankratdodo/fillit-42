/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:47:43 by caellis           #+#    #+#             */
/*   Updated: 2019/06/13 14:57:58 by caellis          ###   ########.fr       */
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
	char			index;		// Letter
	char			*shape;		// some str containing square
	char			width;		// length of a side
	struct s_tetris	*next;
}					t_tetris;

# define MALL_CHECK(x) if (!(x)) return (NULL)
# define ERR_ZERO(x) if (!(x)) return (0)

t_tetris    		*map_2_figures(char const *map, t_tetris **figures, char q);
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

void				print_figure(t_tetris *fig);
t_tetris			*new_figure(char const *s_fig, char i);
void				add_figure(t_tetris **figs, t_tetris *new);

#endif
