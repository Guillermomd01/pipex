/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:16:30 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/13 18:24:31 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
// int main(void)
// {
// 	t_list 	*nodo1;
// 	t_list	*nodo2;
// 	t_list	*nodo3;
// 	nodo1 = ft_lstnew("hola");
// 	nodo2 = ft_lstnew("adios");
// 	nodo3 = ft_lstnew("como stas ");
// 	nodo1->next = nodo2;
// 	nodo2->next = nodo3;
// 	printf("%d", ft_lstsize(nodo1));
// }
