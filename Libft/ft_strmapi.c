/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:32:28 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/05 14:11:16 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	t;

	if (s && f)
	{
		str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!str)
			return (NULL);
		t = 0;
		while (s[t])
		{
			str[t] = f(t, s[t]);
			t++;
		}
		str[t] = '\0';
		return (str);
	}
	return (NULL);
}
