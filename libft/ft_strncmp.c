/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:06:45 by plettie           #+#    #+#             */
/*   Updated: 2019/04/15 13:28:27 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*src;

	str = (unsigned char *)s1;
	src = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	n--;
	while (str[i] == src[i] && str[i] && i < n)
		i++;
	return (str[i] - src[i]);
}
