/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:46:28 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/05 18:11:06 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int i;

	i = -1;
	while ((size_t)++i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
