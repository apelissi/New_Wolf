/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:02:42 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/27 21:05:36 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char	*t;
	int		i;
	int		len;

	if (n > (len = ft_strlen(s)))
		n = len;
	if (!(t = (char *)malloc((n + 1) * sizeof(char))) || n < 0)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
