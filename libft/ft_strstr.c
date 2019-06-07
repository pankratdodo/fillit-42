/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:34:35 by caellis           #+#    #+#             */
/*   Updated: 2019/04/18 19:29:44 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*gotcha;
	const char	*reset;

	reset = needle;
	if (!*needle || needle == haystack)
		return ((char *)haystack);
	while (*haystack)
	{
		gotcha = haystack;
		while (*haystack == *needle && *needle)
		{
			haystack++;
			needle++;
		}
		if (!*needle)
			return ((char *)gotcha);
		needle = reset;
		haystack = gotcha + 1;
	}
	return (NULL);
}
