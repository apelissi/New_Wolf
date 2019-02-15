/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbtlejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:49:49 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/28 13:50:44 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_sbtlejoin(char *old, char *ajout)
{
	char	*new;

	if (!old && !ajout)
		return (NULL);
	else if (!old)
		return (ft_strdup(ajout));
	else if (!ajout)
		return (old);
	new = ft_strjoin(old, ajout);
	return (new);
}
