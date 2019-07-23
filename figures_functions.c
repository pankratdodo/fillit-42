/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:02:51 by caellis           #+#    #+#             */
/*   Updated: 2019/07/23 15:17:00 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point	*copy_shape(t_point *shape)
{
	t_point		*copy;
	int			p_num;

	p_num = 0;
	MALL_CHECK(copy = (t_point *)malloc(sizeof(t_point) * 4));
	if (shape)
	{
		while (p_num < 4)
		{
			copy[p_num].x = shape[p_num].x;
			copy[p_num].y = shape[p_num].y;
			p_num++;
		}
	}
	return (copy);
}

t_tetris		*new_figure(char i, char number, t_point *shape)
{
	t_tetris	*fig;

	MALL_CHECK(fig = (t_tetris *)malloc(sizeof(t_tetris)));
	fig->index = i;
	fig->number = number;
	fig->shape = copy_shape(shape);
	fig->next = NULL;
	return (fig);
}

void			add_figure(t_tetris **figs, t_tetris *new)
{
	t_tetris	*buff;

	if (figs && (!*figs) && new)
		*figs = new;
	else if (figs && *figs && new)
	{
		buff = *figs;
		while (buff->next)
			buff = buff->next;
		buff->next = new;
	}
}

void			abs_point_2_shape(t_point **shape, int p_num, int x, int y)
{
	if (shape && *shape)
	{
		(*shape)[p_num].x = x;
		(*shape)[p_num].y = y;
	}
}

t_point			*set_shape(t_point **shape)
{
	int			x_base;
	int			y_base;
	int			p_num;

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
