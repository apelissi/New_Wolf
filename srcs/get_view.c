/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:10:07 by apelissi          #+#    #+#             */
/*   Updated: 2019/02/21 16:46:27 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	point(int x, int y, t_map *m)
{
	int	x_m;
	int	y_m;

	x_m = x * m->img_x / (TS * m->t_x);
	y_m = y * m->img_y / (TS * m->t_y);
	if (m->data_map[x_m + y_m * m->img_x] != BLACK)
		m->data_map[x_m + y_m * m->img_x] = RED;
}

int		ft_color(int num, int p)
{
	if (num == 10)
		return (RED + p * 256);
	else if (num == 1)
		return (GREEN + p);
	else if (num == 2)
		return (YELLOW - p * 256);
	else if (num == 3)
		return (CYAN + p);
	else if (num == -1)
		return (BLACK + p + p * 256);
	else if (num == 0)
		return (PINK - p - p * 256 * 256);
	return (G3 + p);
}

int		truc(int z, int h, t_column c, t_env *e)
{
	float		nz;
	float		nx;
	float		ny;

	if (z >= (e->win_y + h) / 2)
		return (G1);
	else if (z <= (e->win_y - h) / 2)
		return (G3);
	else
	{
		nz = (float)z - (((float)e->win_y - (float)h) / 2);
		nz = nz * (TS / (float)h);
		nx = (int)c.xi % TS;
		ny = (int)c.yi % TS;
		if (c.face == 0)
			return (((int)nz % 25 < 2 || (int)nx % 25 <= 2) ? BLACK : RED);
		else if (c.face == 1)
			return ((int)(ny + nz));
		else if (c.face == 2)
			return ((((int)nx + (int)nz) % 10 < 5) ? PINK : YELLOW);
		else if (c.face == 3)
			return ((((int)ny % 10 < 5 && (int)nz % 10 < 5) ||
					((int)ny % 10 >= 5 && (int)nz % 10 >= 5)) ? CYAN : WHITE);
	}
	return (0);
}

void	make_co2(int h, int i, t_env *e, t_column c)
{
	int	z;

	z = 0;
	i = e->win_x - i;
	while (z < e->win_y)
	{
		e->data[i + e->win_x * z] = truc(z, h, c, e);
		z++;
	}
}

void	get_view(t_env *e)
{
	int			i;
	t_column	c;
	float		d_ecr;
	float		h;
	float		d;

	i = 0;
	d_ecr = (float)e->win_x / (2 * tan(30 * PI / 180));
	while (i <= e->win_x)
	{
		d = (float)e->pe->angle - 30 + (float)i * 60 / (float)e->win_x;
		d = (d < 0) ? 360 + d : d;
		d = (d >= 360) ? d - 360 : d;
		raycast2(d, e->pe, e->map, &c);
		d = (d > (float)e->pe->angle) ?
			d - (float)e->pe->angle : (float)e->pe->angle - d;
		c.d_mur = c.d_mur * cosf(d / 180 * PI);
		h = (d_ecr * TS) / c.d_mur;
		make_co2((int)h, i, e, c);
		i++;
	}
}
