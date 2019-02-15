/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:06:27 by apelissi          #+#    #+#             */
/*   Updated: 2019/02/15 16:41:49 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		is_wall(float x, float y, t_map *m, t_perso *p)
{
	int	mx;
	int	my;

	mx = (p->pos_x < x) ? (int)x / TS - 1 : (int)x / TS;
	my = (p->pos_y < y) ? (int)y / TS - 1 : (int)y / TS;
	mx = (int)x / TS;
	my = (int)y / TS;
	if (mx < 0 || mx >= m->t_x || my < 0 || my >= m->t_y ||
			m->grid[my][mx] == '1' || m->grid[my][mx] == '2')
		return (1);
	return (0);
}

float	findyp(float d, t_perso *p, t_map *m)
{
	float	xm;
	float	ym;
	float	coef;
	float	a;
	int		s;

	coef = cosf(d / 180 * PI) / sinf(d / 180 * PI);
	ym = ((int)(p->pos_y / TS) + 1) * TS;
	xm = (ym - (p->pos_y - coef * p->pos_x)) / coef;
	a = (d < 90) ? 90 - d : d - 270;
	s = (d < 90) ? 1 : -1;
	printf("Xa = %f\n", s * TS * tanf(a / 180 * PI));
	while (!is_wall(xm, ym, m, p))
	{
		xm += s * TS * tanf(a / 180 * PI);
		ym += TS;
	}
	return (hypotf((float)(p->pos_x) - xm, (float)(p->pos_y) - ym));
}

float	findxp(float d, t_perso *p, t_map *m)
{
	float	xm;
	float	ym;
	float	coef;
	float	a;
	int		s;

	coef = cosf(d / 180 * PI) / sinf(d / 180 * PI);
	xm = ((int)(p->pos_x / TS) + 1) * TS;
	ym = coef * xm + p->pos_y - coef * p->pos_x;
	a = (d < 90) ? 90 - d : d - 90;
	s = (d < 90) ? 1 : -1;
	printf("Ya = %f\n", s * TS * tanf(a / 180 * PI));
	while (!is_wall(xm, ym, m, p))
	{
		xm += TS;
		ym += s * TS * tanf(a / 180 * PI);
	}
	return (hypotf((float)(p->pos_x) - xm, (float)(p->pos_y) - ym));
}

float	findym(float d, t_perso *p, t_map *m)
{
	float	xm;
	float	ym;
	float	coef;
	float	a;
	int		s;

	coef = cosf(d / 180 * PI) / sinf(d / 180 * PI);
	ym = (int)(p->pos_x / TS) * TS;
	xm = (ym - (p->pos_y - coef * p->pos_x)) / coef;
	a = (d < 180) ? d - 90 : 270 - d;
	s = (d < 180) ? 1 : -1;
	while (!is_wall(xm, ym, m, p))
	{
		xm += s * TS / tanf(a / 180 * PI);
		ym -= TS;
	}
	return (hypotf((float)(p->pos_x) - xm, (float)(p->pos_y) - ym));
}

float	findxm(float d, t_perso *p, t_map *m)
{
	float	xm;
	float	ym;
	float	coef;
	float	a;
	int		s;

	coef = cosf(d / 180 * PI) / sinf(d / 180 * PI);
	xm = (int)(p->pos_x / TS) * TS;
	ym = coef * xm + p->pos_y - coef * p->pos_x;
	a = (d > 270) ? d - 270 : 270 - d;
	s = (d > 270) ? 1 : -1;
	while (!is_wall(xm, ym, m, p))
	{
		xm -= TS;
		ym += s * TS / tanf(a / 180 * PI);
	}
	return (hypotf((float)(p->pos_x) - xm, (float)(p->pos_y) - ym));
}

void	raycast2(float d, t_perso *p, t_map *m, t_column *c)
{
	float	dx;
	float	dy;
	int		s;
	int		t;

	s = 1;
	if (d == 0 || d == 180)
		dx = -1;
	else if (d < 180)
	{
		dx = findxp(d, p, m);
		s = 2;
	}
	else
		dx = findxm(d, p, m);
	t = 3;
	if (d == 90 || d == 270)
		dy = -1;
	else if (d > 270 || d < 90)
	{
		dy = findyp(d, p, m);
		t = 4;
	}
	else
		dy = findym(d, p, m);
	c->face = (dx < dy && dx != -1) ? s : t;
	printf("d = %f => dx = %f VS dy = %f\n", d, dx, dy);
	if (dx == -1)
		c->d_mur = dy;
	else if (dy == -1)
		c->d_mur = dx;
	else
		c->d_mur = (dx < dy) ? dx : dy;
}
