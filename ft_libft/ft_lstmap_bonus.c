/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:26:57 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/14 12:57:16 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_node(void *content, void (*del)(void *))
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
		del (content);
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp_list;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_content = f(lst->content);
	new_list = create_node(new_content, del);
	if (!new_list)
		return (NULL);
	temp_list = new_list;
	lst = lst->next;
	while (lst)
	{
		new_content = f(lst->content);
		temp_list->next = create_node(new_content, del);
		if (!temp_list->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		temp_list = temp_list->next;
		lst = lst->next;
	}
	return (new_list);
}
