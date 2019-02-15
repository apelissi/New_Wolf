/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:02:41 by apelissi          #+#    #+#             */
/*   Updated: 2017/11/30 13:07:05 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	t;

	t = 0;
	while (t < n && src[t])
	{
		dest[t] = src[t];
		t++;
	}
	while (t < n)
	{
		dest[t] = '\0';
		t++;
	}
	return (dest);
}
