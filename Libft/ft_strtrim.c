/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:23:54 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/05 14:26:15 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_espace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static unsigned int	ft_start(char const *s)
{
	unsigned int	start;

	start = 0;
	while (is_espace(s[start]) && s[start])
		start++;
	return (start);
}

char				*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	start;
	size_t			len;
	size_t			t;

	if (!s)
		return (NULL);
	len = 0;
	t = 0;
	start = ft_start(s);
	while (s[start + t])
	{
		while (!(is_espace(s[start + len])) && s[start + len])
		{
			len++;
			t++;
		}
		while (is_espace(s[start + t]) && s[start + t])
			t++;
		if (!(is_espace(s[start + t])) && s[start + t])
			len = t;
	}
	if (!(str = ft_strsub(s, start, len)))
		return (NULL);
	return (str);
}
