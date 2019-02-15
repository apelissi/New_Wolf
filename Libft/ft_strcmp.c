/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:28:57 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/04 20:42:12 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	t;

	t = 0;
	while ((unsigned char)s1[t] == (unsigned char)s2[t] && s1[t])
		t++;
	return ((unsigned char)s1[t] - (unsigned char)s2[t]);
}
