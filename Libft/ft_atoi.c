/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:55:06 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/05 20:11:04 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static int		is_int(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *nptr)
{
	size_t	i;
	int		res;
	int		s;
	size_t	j;

	s = 1;
	i = 0;
	res = 0;
	j = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\r' ||
			nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\t')
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-') && is_int(nptr[i + 1]))
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (is_int(nptr[i]) && is_int(nptr[i + 1]))
		res = 10 * (res + s * (nptr[i++] - '0'));
	if (is_int(nptr[i]))
		res += s * (nptr[i] - '0');
	return (res);
}
