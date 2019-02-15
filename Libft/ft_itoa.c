/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:18:26 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/05 16:51:48 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*magouille(size_t t, int n)
{
	char	*str;

	if (n < 0)
	{
		str = ft_strnew(t + 1);
		str[0] = '-';
	}
	else
		str = ft_strnew(t);
	return (str);
}

static int	pos(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char		*ft_itoa(int n)
{
	size_t	t;
	int		div;
	size_t	i;
	char	*str;

	div = 1;
	t = 1;
	i = 0;
	while (n / div > 9 || n / div < -9)
	{
		div = div * 10;
		t++;
	}
	if (!(str = magouille(t, n)))
		return (NULL);
	if ((t = pos(n)) == -1)
		i++;
	while (div)
	{
		str[i] = '0' + t * n / div;
		n = n % div;
		div = div / 10;
		i++;
	}
	return (str);
}
