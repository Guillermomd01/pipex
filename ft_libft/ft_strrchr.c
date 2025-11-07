/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:55:28 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/06 18:10:03 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	t;

	t = ft_strlen(s);
	while (t + 1)
	{
		if (s[t] == (char)c)
			return ((char *)&s[t]);
		t--;
	}
	return (NULL);
}
/*
int main(void)
{
	char f[] = "Hola como";
	printf("%p\n", ft_strrchr(f,'a'));
	printf("%p", strrchr(f,'a'));
	return 0;
}*/
