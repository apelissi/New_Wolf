/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:27:03 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/05 14:16:49 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	t;

	if (s && f)
	{
		str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!str)
			return (NULL);
		t = 0;
		while (s[t])
		{
			str[t] = f(s[t]);
			t++;
		}
		str[t] = '\0';
		return (str);
	}
	return (NULL);
}
