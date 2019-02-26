/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:05:58 by apelissi          #+#    #+#             */
/*   Updated: 2019/01/21 18:09:22 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		expose_hook(t_env *e)
{
	int	i;

	i = 0;
	if (e->psi)
		e->p = (e->p + 3) % 256;
	if (e->f == 0)
	{
		e->map->img_map = mlx_new_image(e->ptr, e->map->img_x, e->map->img_y);
		e->map->data_map = \
		(int *)mlx_get_data_addr(e->map->img_map, &i, &i, &i);
		e->img = mlx_new_image(e->ptr, e->win_x, e->win_y);
		e->data = (int *)mlx_get_data_addr(e->img, &i, &i, &i);
		get_grid(e);
		e->f = e->f + 1;
	}
	get_perso(e, e->pe);
	get_view(e);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	if (e->pm)
		mlx_put_image_to_window(e->ptr, e->win, e->map->img_map, 0, 0);
	erase_player(e, e->pe->y_map, e->pe->x_map);
	return (i);
}
