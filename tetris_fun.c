/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:02:51 by caellis           #+#    #+#             */
/*   Updated: 2019/06/12 19:16:40 by caellis          ###   ########.fr       */
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
			"shape is: '%s'\n"\
			"width is: '%i'\n", \
				fig->index, fig->shape, \
				fig->width);
}

t_tetris	*new_figures(void)
{
	t_tetris	*fig;

	if ((fig = (t_tetris *)malloc(sizeof(t_tetris))))
	{
		fig->index = 'A';
		fig->shape = ft_strnew(0);
		fig->width = 0;
		fig->next = NULL;
	}
	return (NULL);
}
