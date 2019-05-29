/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:51:23 by plettie           #+#    #+#             */
/*   Updated: 2019/04/15 17:17:07 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*str;
	void	*con;
	size_t	size;

	if (!(str = (t_list *)malloc(sizeof(t_list) * content_size)))
		return (0);
	if (content == NULL)
	{
		str->content = NULL;
		str->content_size = 0;
	}
	else
	{
		con = ft_memalloc(content_size);
		size = content_size;
		ft_memcpy(con, content, content_size);
		str->content = con;
		str->content_size = size;
	}
	str->next = NULL;
	return (str);
}
