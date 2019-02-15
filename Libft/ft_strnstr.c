/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:04:54 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/04 20:40:43 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "libft.h"

char	*ft_strnstr(const char *meule, const char *aiguille, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	t_aig;

	t_aig = ft_strlen(aiguille);
	i = 0;
	j = 0;
	if (!t_aig)
		return ((char *)meule);
	while (meule[i] && i < len)
	{
		if (meule[i] == aiguille[j])
		{
			while (meule[i + j] == aiguille[j] && (i + j) < len && j < t_aig)
				j++;
			if (j == t_aig)
				return ((char *)&meule[i]);
			else
				j = 0;
		}
		i++;
	}
	return (NULL);
}
