/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:51:52 by caellis           #+#    #+#             */
/*   Updated: 2019/05/06 16:12:31 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;

	map = NULL;
	if (s && f)
	{
		map = ft_strdup(s);
		while (map && *map)
		{
			*map = (*f)(*map);
			map++;
		}
	}
	return (map);
}
