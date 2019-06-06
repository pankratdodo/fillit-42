/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:47:34 by caellis           #+#    #+#             */
/*   Updated: 2019/04/27 16:17:13 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*buff;

	buff = dst;
	if (len)
	{
		while (len && *src)
		{
			*(buff++) = *(src++);
			len--;
		}
		if (len)
			ft_bzero(buff, len);
	}
	return (dst);
}
