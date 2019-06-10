/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:22:50 by plettie           #+#    #+#             */
/*   Updated: 2019/04/12 17:06:32 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;
	char	k;

	d = (char *)dest;
	s = (char *)src;
	k = (char)c;
	i = 0;
	while (n > i)
	{
		d[i] = s[i];
		if (s[i] == k)
			return (&d[i + 1]);
		i++;
	}
	return (0);
}
