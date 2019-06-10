/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:02:51 by caellis           #+#    #+#             */
/*   Updated: 2019/06/10 19:48:12 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* We could collect functions for t_tetris type here
* e.g. iter_figures, push_figure, pop_figure, delete_figure,
* clear_figures, map_figures etc
*/

#include "fillit.h"

void		print_figure(t_tetris *fig)
{
	printf("index is: '%c'\n"\
			"shape is: '%X'\n"\
			"xl is: '%i', xh is: '%i'\n"\
			"yl is: '%i', yh is: '%i'\n", \
				fig->index, fig->shape, \
				fig->xl, fig->xh, fig->yl, fig->yh);
}

