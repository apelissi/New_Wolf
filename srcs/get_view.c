/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:10:07 by apelissi          #+#    #+#             */
/*   Updated: 2019/02/21 17:02:13 by apelissi         ###   ########.fr       */
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

int		co(int num, int p)
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
	else if (num == 4)
		return (WHITE + p * 65622);
	return (G3 + p);
}

int		render(t_render r, int h, t_column c, t_env *e)
{
	if (r.z >= (e->win_y + h) / 2)
		return (G1 + e->p);
	else if (r.z <= (e->win_y - h) / 2)
		return (G3 + e->p);
	else
	{
		if (c.face == 0)
			return (((int)r.nz % 25 <= 0 || (int)r.nz % 25 >= 24 || (int)r.nx %
			25 <= 0 || (int)r.nx % 25 >= 24) ? co(-1, e->p) : co(10, e->p));
		else if (c.face == 1)
			return ((int)(r.ny + r.nz) + e->p);
		else if (c.face == 2)
			return ((((int)r.nx + (int)r.nz) % 10 < 5) ?
			co(0, e->p) : co(2, e->p));
		else if (c.face == 3)
			return ((((int)r.ny % 10 < 5 && (int)r.nz % 10 < 5) || ((int)r.ny %
			10 >= 5 && (int)r.nz % 10 >= 5)) ? co(3, e->p) : co(4, e->p));
	}
	return (0);
}

void	make_co(int h, int i, t_env *e, t_column c)
{
	t_render r;

	r.z = 0;
	r.nx = (int)c.xi % TS;
	r.ny = (int)c.yi % TS;
	i = e->win_x - i;
	while (r.z < e->win_y)
	{
		r.nz = ((float)r.z - (((float)e->win_y - (float)h) / 2))
		* (TS / (float)h);
		e->data[i + e->win_x * r.z] = render(r, h, c, e);
		r.z++;
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
		raycast(d, e->pe, e->map, &c);
		d = (d > (float)e->pe->angle) ?
			d - (float)e->pe->angle : (float)e->pe->angle - d;
		c.d_mur = c.d_mur * cosf(d / 180 * PI);
		h = (d_ecr * TS) / c.d_mur;
		make_co((int)h, i, e, c);
		i++;
	}
}
