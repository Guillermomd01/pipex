/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:08:00 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/13 18:08:48 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	if (dest == src)
		return (dest);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char p[] = "Holaaa";
	char q[] = "";
	printf("%p\n",ft_memcpy(p,q,6));
	printf("%p",memcpy(p,q,6));
	return (0);
}*/
