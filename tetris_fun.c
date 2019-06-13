/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:02:51 by caellis           #+#    #+#             */
/*   Updated: 2019/06/13 14:40:28 by caellis          ###   ########.fr       */
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
			"shape is: '%s'\n"\
			"width is: '%i'\n", \
				fig->index, fig->shape, \
				fig->width);
}

t_tetris	*new_figure(char const *s_fig, char i)
{
	t_tetris	*fig;

	MALL_CHECK(fig = (t_tetris *)malloc(sizeof(t_tetris)));
	MALL_CHECK(fig->shape = ft_strdup(s_fig));
	fig->index = i;
	fig->width = 4;
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