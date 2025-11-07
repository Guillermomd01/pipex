/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:53:47 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/13 18:11:59 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_temp = ft_lstlast (*lst);
	lst_temp->next = new;
	return ;
}
