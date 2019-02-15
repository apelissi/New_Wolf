/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:31:56 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/27 21:06:01 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_tab(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			size++;
		i++;
	}
	return (size);
}

int		size_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;
	int		s_word;
	int		i;

	size = size_tab(s, c);
	if (!size || !(tab = (char **)malloc((size + 1) * sizeof(char *))))
		return (NULL);
	tab[size] = NULL;
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			s_word = size_word(&s[i], c);
			tab[size] = ft_strndup(&s[i], s_word);
			size++;
			i = i + s_word - 1;
		}
		i++;
	}
	return (tab);
}
