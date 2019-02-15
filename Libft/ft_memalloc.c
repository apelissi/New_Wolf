/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:01:01 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/04 13:48:02 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;
	size_t			t;

	res = malloc(size);
	if (!res)
		return (NULL);
	t = 0;
	while (t < size)
	{
		res[t] = '\0';
		t++;
	}
	return (res);
}
