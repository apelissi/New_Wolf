/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtapcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:18:01 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/27 21:03:12 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabcpy(char **dest, char **src, int i)
{
	size_t	t;

	if (!dest || !src)
		return (NULL);
	t = 0;
	while (src[t] && t < (size_t)i)
	{
		dest[t] = src[t];
		t++;
	}
	return (dest);
}
