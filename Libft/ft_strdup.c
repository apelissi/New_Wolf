/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:49:31 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/02 18:38:13 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	int		i;

	i = 0;
	t = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!t)
		return (NULL);
	while (s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
