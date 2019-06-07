/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 02:58:26 by caellis           #+#    #+#             */
/*   Updated: 2019/05/06 16:26:44 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;

	joint = NULL;
	if (s1 && s2)
	{
		if ((joint = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			ft_strcat(ft_strcpy(joint, s1), s2);
	}
	return (joint);
}
