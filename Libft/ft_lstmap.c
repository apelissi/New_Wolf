/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 21:05:17 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/27 21:05:18 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (lst->next == NULL)
	{
		if (!(new = f(lst)))
			return (NULL);
		return (new);
	}
	else
	{
		if (!(new = f(lst)))
			return (NULL);
		new->next = ft_lstmap(lst->next, f);
		return (new);
	}
}
