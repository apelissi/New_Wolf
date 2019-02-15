/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:49:19 by apelissi          #+#    #+#             */
/*   Updated: 2017/11/30 11:43:12 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	dp = dest;
	sp = src;
	while (n--)
		*dp++ = *sp++;
	return (dest);
}
