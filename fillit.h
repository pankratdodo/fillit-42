/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:47:43 by caellis           #+#    #+#             */
/*   Updated: 2019/07/23 16:22:22 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tetris
{
	char			index;
	char			number;
	t_point			*shape;
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

char				is_valid(int fd);
t_cell				*solve_it(t_tetris *figures, char side);

#endif

#ifndef FIGURES_FUNCTIONS_H
# define FIGURES_FUNCTIONS_H

t_tetris			*new_figure(char i, char number, t_point *shape);
void				add_figure(t_tetris **figs, t_tetris *new);
void				abs_point_2_shape(t_point **shape, int p_num, int x, int y);
t_point				*set_shape(t_point **shape);
#endif

#ifndef UTILITIES_H
# define UTILITIES_H

char				ez_sqrt(int x);
int					ft_urod(char *c);
void				cleaner(t_tetris **figures, t_cell **map, char **input);
#endif

#ifndef MAP_FUNCTIONS_H
# define MAP_FUNCTIONS_H

t_tetris			*map_2_figures(char const *map, t_tetris *figures, char q);
void				print_map(t_cell *c_map, char side);
t_cell				*map_init(char side);
#endif
