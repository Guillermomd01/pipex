/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:36:59 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/13 18:39:09 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	real_len;
	size_t	j;
	char	*m;

	if (!s)
		return (NULL);
	real_len = ft_strlen(s);
	if (start >= real_len)
		return (ft_strdup(""));
	if (len > real_len - start)
		len = real_len - start;
	m = malloc(len + 1);
	if (!m)
		return (NULL);
	j = 0;
	while (s[start + j] && j < len)
	{
		m[j] = s[start + j];
		j++;
	}
	m[j] = '\0';
	return (m);
}
