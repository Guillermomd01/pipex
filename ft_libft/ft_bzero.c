/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:58:10 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/06 15:45:47 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	void	*p;

	p = ft_memset(s, 0, n);
	return ((void)&p);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char p[]= "hello";

	printf("%s\n",ft_bzero(p,4));
	printf("%s\n", bzero(p,4));
	return 0;
}*/
