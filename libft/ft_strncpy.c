/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:36:53 by plettie           #+#    #+#             */
/*   Updated: 2019/04/04 17:30:18 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i != len)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < len)
	{
		while (i < len)
		{
			dst[i] = 0;
			i++;
		}
	}
	return (dst);
}
