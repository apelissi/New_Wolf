/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:47:44 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/06 15:40:08 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(char **tab_str, int i)
{
	size_t	t;
	char	**res;

	t = 0;
	if (!tab_str)
		return (NULL);
	while (tab_str[t] && t < (size_t)i)
		t++;
	res = (char **)malloc((t + 1) * sizeof(char *));
	t = 0;
	while (tab_str[t] && t < (size_t)i)
	{
		res[t] = ft_strdup(tab_str[t]);
		t++;
	}
	return (res);
}
