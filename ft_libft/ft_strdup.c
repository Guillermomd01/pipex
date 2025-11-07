/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:31:53 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/06 16:11:05 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		l;
	char		*m;

	l = ft_strlen(s) +1;
	m = malloc(l);
	if (!m)
		return (NULL);
	ft_strlcpy(m, s, l);
	return (m);
}
