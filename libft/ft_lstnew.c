/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:10:07 by caellis           #+#    #+#             */
/*   Updated: 2019/05/06 17:48:30 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list *)malloc(sizeof(t_list))))
	{
		if (!content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else if ((list->content = (void *)malloc(content_size)))
		{
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		else
			return (NULL);
		list->next = NULL;
	}
	return (list);
}
