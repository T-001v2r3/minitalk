/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:16:32 by gperfeit          #+#    #+#             */
/*   Updated: 2024/03/05 14:49:19 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*create_new_node(void *(*f)(void *), void (*del)(void *), void *content)
{
	t_list	*new;

	content = f(content);
	new = ft_lstnew(content);
	if (!new)
	{
		del(content);
		return (NULL);
	}
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	new = create_new_node(f, del, lst->content);
	if (!new)
		return (NULL);
	ret = new;
	lst = lst->next;
	while (lst)
	{
		new = create_new_node(f, del, lst->content);
		if (!new)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, new);
		lst = lst->next;
	}
	return (ret);
}
