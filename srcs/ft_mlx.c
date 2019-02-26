/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:25:58 by apelissi          #+#    #+#             */
/*   Updated: 2019/02/14 16:21:15 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	init(t_env *e)
{
	e->win_x = 900;
	e->win_y = 700;
	e->map->img_x = 250;
	e->map->img_y = 250;
	e->pe->pos_x = -1;
	e->f = 0;
	e->pe->angle = 0;
	e->pe->mv_y = 0;
	e->pe->mv_x = 0;
	e->pe->mv_r = 0;
	e->psi = 0;
	e->p = 0;
	e->pm = 0;
}

int		ft_mlx(t_env *e)
{
	init(e);
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, e->win_x, e->win_y, "Wolf3D");
	mlx_hook(e->win, 17, 0, ft_click_exit, e);
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 3, (1L << 1), key_release, e);
	mlx_loop_hook(e->ptr, expose_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->ptr);
	return (0);
}
