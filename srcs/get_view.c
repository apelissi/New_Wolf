/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:10:07 by apelissi          #+#    #+#             */
/*   Updated: 2019/02/15 16:34:35 by apelissi         ###   ########.fr       */
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
	if (num == 0)
		return (RED + p * 256);
	else if (num == 1)
		return (GREEN + p);
	else if (num == 2)
		return (YELLOW - p * 256);
	else if (num == 3)
		return (CYAN - p);
	else if (num == -1)
		return (BLACK + p + p * 256);
	else if (num == 10)
		return (PINK);
	return (G3 + p);
}

void	make_co(int h, int i, t_env *e, t_column c)
{
	int a;
	int color;

	a = 0;
	i = e->win_x - i;
	color = WHITE + e->p + e->p / 3 * 256 + e->p * 256 * 256;
	while (a < e->win_y)
	{
		if (a >= (e->win_y + h) / 2)
			color = (e->p) ? e->p * (1 + 256 + 256 * 256) : G1;
		e->data[i + e->win_x * a] =
			(a > (e->win_y - h) / 2 && a < (e->win_y + h) / 2)
			? ft_color(c.face, e->p) : color;
		a++;
	}
}

void	raycast(float d, t_perso *p, t_map *m, t_column *c)
{
	float	x_t;
	float	y_t;

	x_t = p->pos_x;
	y_t = p->pos_y;
	while (x_t >= 0 && x_t < m->t_x * TS && y_t >= 0 && y_t < m->t_y * TS
			&& (m->grid[(int)(y_t / TS)][(int)(x_t / TS)] != '1')
			&& (m->grid[(int)(y_t / TS)][(int)(x_t / TS)] != '2'))
	{
		x_t = x_t + sinf(d / 180 * PI);
		y_t = y_t + cosf(d / 180 * PI);
	}
	if (m->pal)
		get_column(c, x_t, y_t);
	c->d_mur = hypotf((float)(p->pos_x) - x_t, (float)(p->pos_y) - y_t);
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
		if (d)
			raycast2(d, e->pe, e->map, &c);
		else
			raycast(d, e->pe, e->map, &c);
		d = (d > (float)e->pe->angle) ?
			d - (float)e->pe->angle : (float)e->pe->angle - d;
		c.d_mur = c.d_mur * cosf(d / 180 * PI);
		h = (d_ecr * TS) / c.d_mur;
		make_co((int)h, i, e, c);
		i++;
	}
}
