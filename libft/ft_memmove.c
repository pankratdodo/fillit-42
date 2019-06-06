/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 10:15:11 by caellis           #+#    #+#             */
/*   Updated: 2019/05/06 17:32:30 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buff;
	unsigned char	*cast;

	buff = (unsigned char *)dst;
	cast = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if ((size_t)(dst - src) < len)
	{
		cast += (len - 1);
		buff += (len - 1);
		while (len--)
			*(buff--) = *(cast--);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
