/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:04:58 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/27 21:05:00 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst[0]->next == NULL)
		ft_lstdelone(alst, del);
	else
	{
		ft_lstdel(&alst[0]->next, del);
		ft_lstdelone(alst, del);
	}
}
