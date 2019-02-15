/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:13:00 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/05 14:13:56 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	t;

	str = ft_strnew(len);
	if (!str || !s)
		return (NULL);
	t = 0;
	while (t < len)
	{
		str[t] = s[start + t];
		t++;
	}
	return (str);
}
