/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:19:57 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/05 20:40:26 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			t;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	t = len;
	if (dst > src)
	{
		while (t > 0)
		{
			dest[t - 1] = source[t - 1];
			t--;
		}
	}
	else if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
