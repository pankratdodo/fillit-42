/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:52:21 by caellis           #+#    #+#             */
/*   Updated: 2019/05/04 17:17:35 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	i = 0;
	map = NULL;
	if (s && f)
	{
		map = ft_strdup(s);
		while (map && map[i])
		{
			map[i] = (*f)(i, map[i]);
			i++;
		}
	}
	return (map);
}
