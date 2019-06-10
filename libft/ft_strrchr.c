/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:25:58 by plettie           #+#    #+#             */
/*   Updated: 2019/04/12 17:13:58 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	k;
	char	*str;

	i = 0;
	k = (char)c;
	str = (char*)s;
	while (str[i])
		i++;
	while (str[i] != k)
	{
		if (i < 0)
			return (0);
		i--;
	}
	return (&str[i]);
}
