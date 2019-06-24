/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:02:51 by caellis           #+#    #+#             */
/*   Updated: 2019/06/24 13:58:34 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* We could collect functions for t_tetris type here
* e.g. iter_figures, pop_figure, delete_figure,
* clear_figures, map_figures etc
*/

#include "fillit.h"

void		print_figure(t_tetris *fig)
{
	printf("index is: '%c'\n"\
			"1st point is: '%i, %i'\n"\
			"2nd point is: '%i, %i'\n"\
			"3rd point is: '%i, %i'\n"\
			"4th point is: '%i, %i'\n", \
				fig->index, fig->shape[0].x, fig->shape[0].y, \
				fig->shape[1].x, fig->shape[1].y, \
				fig->shape[2].x, fig->shape[2].y, \
				fig->shape[3].x, fig->shape[3].y);
}

t_tetris	*new_figure(char i, t_point *shape)
{
	t_tetris	*fig;

	MALL_CHECK(fig = (t_tetris *)malloc(sizeof(t_tetris)));
	fig->index = i;
	fig->shape = shape;
	fig->next = NULL;
	return (fig);
}

void		add_figure(t_tetris **figs, t_tetris *new)
{
	t_tetris	*buff;

	if (figs && (!*figs) && new)
		*figs = new;
	else if (figs && *figs && new)
	{
		while ((*figs)->next)
			*figs = (*figs)->next;
		(*figs)->next = new;
	}
}

void		abs_point_2_shape(t_point **shape, int p_num, int x, int y)
{
	if (shape && *shape)
	{
		shape[p_num]->x = x;
		shape[p_num]->y = y;
	}
}

t_point		*set_shape(t_point **shape)
{
	int		x_base;
	int		y_base;
	int		p_num;

	p_num = 0;
	if (shape && *shape)
	{
		x_base = (*shape)[p_num].x;
		y_base = (*shape)[p_num].y;
		while (p_num < 4)
		{
			(*shape)[p_num].x -= x_base;
			(*shape)[p_num].y -= y_base;
			p_num++;
		}
	}
	return (*shape);
}