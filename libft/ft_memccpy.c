/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:56:14 by caellis           #+#    #+#             */
/*   Updated: 2019/04/11 10:44:56 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*buff;
	unsigned char	*cast;

	buff = (unsigned char *)dst;
	cast = (unsigned char *)src;
	while (n--)
	{
		*(buff++) = *(cast++);
		if (*(cast - 1) == (unsigned char)c)
			return (buff);
	}
	return (NULL);
}
