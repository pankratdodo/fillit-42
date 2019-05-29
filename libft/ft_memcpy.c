/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 10:49:03 by plettie           #+#    #+#             */
/*   Updated: 2019/04/12 17:07:44 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (0);
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
