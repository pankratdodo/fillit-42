/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:07:19 by plettie           #+#    #+#             */
/*   Updated: 2019/04/17 11:55:35 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*str;
	t_list	*s;

	if (!lst || !f)
		return (0);
	s = f(lst);
	if ((res = ft_lstnew(s->content, s->content_size)))
	{
		str = res;
		lst = lst->next;
		while (lst != NULL)
		{
			s = (*f)(lst);
			if (!(str->next = ft_lstnew(s->content, s->content_size)))
				return (NULL);
			str = str->next;
			lst = lst->next;
		}
	}
	return (res);
}
