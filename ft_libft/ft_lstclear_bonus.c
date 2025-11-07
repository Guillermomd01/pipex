/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:06:33 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/13 18:16:07 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*temp_lst;

	if (!*lst)
	{
		*lst = NULL;
		return ;
	}
	while (*lst)
	{
		temp_lst = (*lst)-> next;
		del((*lst)->content);
		free(*lst);
		*lst = temp_lst;
	}
	return ;
}
