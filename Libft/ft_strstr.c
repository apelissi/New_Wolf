/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:34:25 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/02 18:43:11 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	size_t	i;
	size_t	j;
	size_t	taille_aiguille;

	taille_aiguille = ft_strlen(aiguille);
	i = 0;
	j = 0;
	if (!taille_aiguille)
		return ((char *)meule_de_foin);
	while (meule_de_foin[i])
	{
		if (meule_de_foin[i] == aiguille[j])
		{
			while (meule_de_foin[i + j] == aiguille[j] && j < taille_aiguille)
				j++;
			if (j == taille_aiguille)
				return ((char *)&meule_de_foin[i]);
			else
				j = 0;
		}
		i++;
	}
	return (NULL);
}
