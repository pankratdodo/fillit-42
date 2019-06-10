/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:56:39 by plettie           #+#    #+#             */
/*   Updated: 2019/04/09 13:36:08 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (s2 < s1)
	{
		while (len > 0)
		{
			s1[len - 1] = s2[len - 1];
			len--;
		}
	}
	else
		s1 = ft_newstr(&s1[i], &s2[i], len);
	return ((void *)s1);
}
