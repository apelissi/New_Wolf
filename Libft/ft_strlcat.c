/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:21:19 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/04 19:45:21 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		l;

	if (!(dest) || !(src))
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	l = size;
	j = 0;
	k = ft_strlen(src);
	i = ft_strlen(dest);
	while (src[j] && (i + j) < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	if (k + size <= k + i && l >= 0)
		return (k + size);
	return (k + i);
}
