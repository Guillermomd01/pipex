/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumunoz <gumunoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:24:09 by gumunoz           #+#    #+#             */
/*   Updated: 2025/10/14 18:51:30 by gumunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static size_t	word_len(const char *p, char c)
{
	size_t	i ;

	i = 0;
	while (p[i] && p[i] != c)
		i++;
	return (i);
}

static char	**free_split(char **result, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static void	ft_init_var(int *i, int *k)
{
	*i = 0;
	*k = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i ;
	int		k;
	size_t	len;

	ft_init_var(&i, &k);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			len = word_len(&s[i], c);
			result[k] = malloc(len + 1);
			if (!result[k])
				return (free_split(result, k));
			ft_strlcpy(result[k], &s[i], len + 1);
			k++;
			i += len;
		}
	}
	return (result[k] = NULL, result);
}
// int main(void){
// 	char *s = NULL;
// 	ft_split(s,'r');
// }