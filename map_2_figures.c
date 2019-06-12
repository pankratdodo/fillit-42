/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:08:15 by caellis           #+#    #+#             */
/*   Updated: 2019/06/12 19:17:59 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris    *map_2_figures(char const *map, t_tetris **figures, char q)
{
	size_t	i;
	t_tetris	figures;

	if(!(figures = new_figures()))
		return(NULL);
	while (map++)
	{
		// делай кайф :)
	}
	return (NULL);
}