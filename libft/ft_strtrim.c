/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:21:40 by caellis           #+#    #+#             */
/*   Updated: 2019/05/04 17:12:47 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		cue;

	trim = NULL;
	if (s)
	{
		while (ft_isspace(*s))
			s++;
		cue = ft_strlen(s) - 1;
		while (cue > -1 && ft_isspace(s[cue]))
			cue--;
		cue++;
		if ((trim = ft_strnew(cue)))
			ft_strncpy(trim, s, cue);
	}
	return (trim);
}
