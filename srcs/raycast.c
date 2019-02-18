/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:06:27 by apelissi          #+#    #+#             */
/*   Updated: 2019/02/18 17:25:59 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		is_wall(float x, float y, t_map *m, int f)
{
	int	mx;
	int	my;

	mx = (int)x / TS - f % 2;
	my = (int)y / TS - f % 3;
	if (mx < 0 || mx >= m->t_x || my < 0 || my >= m->t_y ||
			m->grid[my][mx] == '1' || m->grid[my][mx] == '2')
		return (1);
	return (0);
}

float	jack0(t_ray r, t_perso *p, t_map *m, int *s)
{
	float	xm;
	float	ym;
	float	xa;
	float	ya;
	float	am;
	float	bm;

	xm = (int)(p->pos_x / TS + 1) * TS;
	ym = r.coef * xm + p->pos_y - r.coef * p->pos_x;
	ya = TS * tanf(r.a / 180 * PI);
	while (!is_wall(xm, ym, m, 6))
	{
		xm += TS;
		ym += ya;
	}
	r.dx = hypotf((float)(p->pos_x) - xm, (float)(p->pos_y) - ym);
	bm = (int)(p->pos_y / TS + 1) * TS;
	am = (bm - (p->pos_y - r.coef * p->pos_x)) / r.coef;
	xa = TS / tanf(r.a / 180 * PI);
	while (!is_wall(am, bm, m, 6))
	{
		am += xa;
		bm += TS;
	}
	r.dy = hypotf((float)(p->pos_x) - am, (float)(p->pos_y) - bm);
	if (r.dx < r.dy)
	{
		*s = 1;
		return (r.dx);
	}
	*s = 2;
	return (r.dy);
}

float	jack1(t_ray r, t_perso *p, t_map *m, int *s)
{
	float	xm;
	float	ym;
	float	xa;
	float	ya;
	float	am;
	float	bm;

	xm = (int)(p->pos_x / TS + 1) * TS;
	ym = r.coef * xm + p->pos_y - r.coef * p->pos_x;
	ya = TS * tanf(r.a / 180 * PI);
	while (!is_wall(xm, ym, m, 6))
	{
		xm += TS;
		ym -= ya;
	}
	r.dx = hypotf((float)(p->pos_x) - xm, (float)(p->pos_y) - ym);
	bm = (int)(p->pos_y / TS) * TS;
	am = (bm - (p->pos_y - r.coef * p->pos_x)) / r.coef;
	xa = TS / tanf(r.a / 180 * PI);
	while (!is_wall(am, bm, m, 4))
	{
		am += xa;
		bm -= TS;
	}
	r.dy = hypotf((float)(p->pos_x) - am, (float)(p->pos_y) - bm);
	if (r.dx < r.dy)
	{
		*s = 1;
		return (r.dx);
	}
	*s = 3;
	return (r.dy);
}

float	jack2(t_ray r, t_perso *p, t_map *m, int *s)
{
	float	xm;
	float	ym;
	float	xa;
	float	ya;
	float	am;
	float	bm;

	xm = (int)(p->pos_x / TS) * TS;
	ym = r.coef * xm + p->pos_y - r.coef * p->pos_x;
	ya = TS * tanf(r.a / 180 * PI);
	while (!is_wall(xm, ym, m, 3))
	{
		xm -= TS;
		ym -= ya;
	}
	r.dx = hypotf((float)(p->pos_x) - xm, (float)(p->pos_y) - ym);
	bm = (int)(p->pos_y / TS) * TS;
	am = (bm - (p->pos_y - r.coef * p->pos_x)) / r.coef;
	xa = TS / tanf(r.a / 180 * PI);
	while (!is_wall(am, bm, m, 4))
	{
		am -= xa;
		bm -= TS;
	}
	r.dy = hypotf((float)(p->pos_x) - am, (float)(p->pos_y) - bm);
	if (r.dx < r.dy)
	{
		*s = 10;
		return (r.dx);
	}
	*s = 3;
	return (r.dy);
}

float	find_dx(t_ray r, t_perso *p, t_map *m)
{
	float	xm;
	float	ym;
	float	ya;

	xm = (int)(p->pos_x / TS + r.cfa) * TS;
	ym = r.coef * xm + p->pos_y - r.coef * p->pos_x;
	ya = TS * tanf(r.a / 180 * PI);
	while (!is_wall(xm, ym, m, 3))
	{
		xm -= TS;
		ym += ya;
	}
	return (hypotf((float)(p->pos_x) - xm, (float)(p->pos_y) - ym));
}

float	find_dy(t_ray r, t_perso *p, t_map *m)
{
	float	am;
	float	bm;
	float	xa;

	bm = (int)(p->pos_y / TS + 1) * TS;
	am = (bm - (p->pos_y - r.coef * p->pos_x)) / r.coef;
	xa = TS / tanf(r.a / 180 * PI);
	while (!is_wall(am, bm, m, 6))
	{
		am -= xa;
		bm += TS;
	}
	return (hypotf((float)(p->pos_x) - am, (float)(p->pos_y) - bm));
}

void	raycast2(float d, t_perso *p, t_map *m, t_column *c)
{
	float	dm;
	int		s;
	t_ray	r;

	r.coef = cosf(d / 180 * PI) / sinf(d / 180 * PI);
	r.a = (d < 180) ? 90 - d : 270 - d;
	r.a = (d > 270 || (d > 90 && d < 180)) ? -r.a : r.a;
	r.cfa = (d < 180) ? 1 : 0;
	s = 0;
	dm = 0;
	if (d < 90)
		dm = jack0(r, p, m, &s);
	else if (d < 180)
		dm = jack1(r, p, m, &s);
	else if (d < 270)
		dm = jack2(r, p, m, &s);
	c->d_mur = dm;
	if (d > 270)
	{
		r.dx = find_dx(r, p, m);
		r.dy = find_dy(r, p, m);
		if (r.dx < r.dy)
		{
			s = 10;
			c->d_mur =  r.dx;
		}
		else
		{
			s = 2;
			c->d_mur =  r.dy;
		}
	}
	c->face = s;
}
