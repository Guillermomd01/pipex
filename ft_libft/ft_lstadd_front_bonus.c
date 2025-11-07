/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:23:27 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/13 18:22:53 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*ferrari;
// 	t_list	*lamborghini;
// 	ferrari = ft_lstnew("motor biturbo");
// 	lamborghini = ft_lstnew("motor simple");
// 	ft_lstadd_front(lamborghini,ferrari);
// 	printf("%s", ferrari);
// }
