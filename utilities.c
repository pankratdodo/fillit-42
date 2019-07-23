/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:37:53 by plettie           #+#    #+#             */
/*   Updated: 2019/07/23 15:59:24 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			ez_sqrt(int x)
{
	int			sqrt;

	sqrt = 1;
	if (x == 2)
		return (1);
	while (sqrt * sqrt <= x)
		sqrt++;
	sqrt--;
	return ((char)sqrt);
}

int				ft_urod(char *c)
{
	int			k;
	int			i;

	k = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] == '.')
			k++;
		i++;
	}
	if (k != 12)
		return (0);
	return (1);
}

void			cleaner(t_tetris **figures, t_cell **map, char **input)
{
	t_tetris	*figs;
	t_tetris	*buff;

	ft_strdel(input);
	free(*map);
	*map = NULL;
	figs = *figures;
	buff = figs;
	while (figs)
	{
		free(figs->shape);
		buff = figs->next;
		free(figs);
		figs = buff;
	}
}
