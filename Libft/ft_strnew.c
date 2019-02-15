/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:10:06 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/04 14:04:17 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	t;

	t = 0;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (t <= size)
	{
		str[t] = '\0';
		t++;
	}
	return (str);
}
