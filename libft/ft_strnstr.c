/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:48:43 by caellis           #+#    #+#             */
/*   Updated: 2019/05/04 18:37:12 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*gotcha;
	const char	*reset;
	int			i;

	reset = needle;
	if (!*needle || needle == haystack)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		gotcha = haystack;
		i = len + 1;
		while (*haystack == *needle && *needle && i--)
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
