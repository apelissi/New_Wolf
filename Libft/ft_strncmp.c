/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:48:52 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/04 20:49:31 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	t;

	if (!n)
		return (0);
	t = 0;
	while ((unsigned char)s1[t] == (unsigned char)s2[t] && s1[t] && t < n)
		t++;
	if (t == n)
		t--;
	return ((unsigned char)s1[t] - (unsigned char)s2[t]);
}
