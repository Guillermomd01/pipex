/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:15:46 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/09 15:27:45 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*sol;
	long	nb;
	int		len;

	nb = n;
	len = ft_len(n);
	sol = malloc(len + 1);
	if (!sol)
		return (NULL);
	sol[len] = '\0';
	if (nb == 0)
	{
		sol[0] = '0';
	}
	if (nb < 0)
	{
		sol[0] = '-';
		nb = nb * -1;
	}
	while (nb)
	{
		sol[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (sol);
}

// int main(void)
// {
// 	int n = 6534;
// 	printf("%s", ft_itoa(n));
// }
