/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:20:47 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/01 19:31:15 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	t;

	t = ft_strlen(s);
	while (s[t] != (char)c && t >= 0)
		t--;
	if (s[t] == (char)c)
		return ((char *)&s[t]);
	else
		return (NULL);
}
