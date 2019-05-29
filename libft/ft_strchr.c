/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:06:35 by plettie           #+#    #+#             */
/*   Updated: 2019/04/12 17:17:43 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	k;

	k = (char)c;
	i = 0;
	while (s[i] != k)
	{
		if (!s[i])
			return (0);
		i++;
	}
	str = (char*)s;
	return (&str[i]);
}
