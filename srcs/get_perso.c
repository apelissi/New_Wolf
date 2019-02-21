/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_perso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:46:04 by apelissi          #+#    #+#             */
/*   Updated: 2019/02/21 12:43:32 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	erase_player(t_env *e, int y_map, int x_map)
{
	int	a;
	int b;

	a = (y_map > 5) ? y_map - 5 : 0;
	while (a <= e->map->img_y && a <= y_map + 5)
	{
		b = (x_map > 5) ? x_map - 5 : 0;
		while (b <= e->map->img_x && b <= x_map + 5)
		{
			if (e->map->data_map[a * e->map->img_x + b] == BLUE)
				e->map->data_map[a * e->map->img_x + b] = G4;
			b++;
		}
		a++;
	}
}

void	make_player(t_env *e, int y_map, int x_map)
{
	int	a;
	int b;

	a = (y_map > 5) ? y_map - 5 : 0;
	while (a <= e->map->img_y && a <= y_map + 5)
	{
		b = (x_map > 5) ? x_map - 5 : 0;
		while (b <= e->map->img_x && b <= x_map + 5)
		{
			if (e->map->data_map[a * e->map->img_x + b] == G4)
				e->map->data_map[a * e->map->img_x + b] = BLUE;
			b++;
		}
		a++;
	}
}

int		check_pos2(int x, int y, t_map *map)
{
	if (x < 0 || x >= TS * map->t_x || y < 0 || y >= TS * map->t_y)
		return (0);
	if (map->grid[y / TS][x / TS] == '1'
			|| map->grid[y / TS][x / TS] == '3')
		return (0);
	return (1);
}

int		check_pos(int x, int y, t_map *map)
{
	if (!(check_pos2(x, y, map)))
		return (0);
	if (!(check_pos2(x + 1, y, map)))
		return (0);
	if (!(check_pos2(x, y + 1, map)))
		return (0);
	if (!(check_pos2(x - 1, y, map)))
		return (0);
	if (!(check_pos2(x, y - 1, map)))
		return (0);
	return (1);
}

void	get_perso(t_env *e, t_perso *p)
{
	float	x;
	float	y;

	p->angle += p->mv_r * VR;
	if (p->angle >= 360 || p->angle < 0)
		p->angle = (p->angle < 0) ? 360 + p->angle : p->angle % 360;
	x = (float)p->pos_x + sin((float)p->angle / 180 * PI) * VD * (float)p->mv_y;
	y = (float)p->pos_y + cos((float)p->angle / 180 * PI) * VD * (float)p->mv_y;
	x += cos((float)p->angle / 180 * PI) * (float)VD * p->mv_x;
	y -= sin((float)p->angle / 180 * PI) * (float)VD * p->mv_x;
	if (check_pos((int)x, (int)y, e->map))
	{
		p->pos_x = (int)x;
		p->pos_y = (int)y;
	}
	else if (check_pos(p->pos_x, y, e->map))
		p->pos_y = y;
	else if (check_pos(x, p->pos_y, e->map))
		p->pos_x = x;
	p->x_map = p->pos_x * (float)e->map->img_x / (TS * e->map->t_x);
	p->y_map = p->pos_y * (float)e->map->img_y / (TS * e->map->t_y);
	make_player(e, p->y_map, p->x_map);
}
