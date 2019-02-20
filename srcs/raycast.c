/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:06:27 by apelissi          #+#    #+#             */
/*   Updated: 2019/02/20 17:08:57 by apelissi         ###   ########.fr       */
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
	{
		if (mx < 0 || mx >= m->t_x || my < 0 || my >= m->t_y)
			return ('1');
		else
			return (m->grid[my][mx]);
	}
	return (0);
}

void	get_all(t_column *c, t_dist d, t_ray r)
{
	if (r.dx < r.dy)
	{
		c->d_mur = r.dx;
		c->num = d.tx;
		c->face = (r.dd < 180) ? 1 : 3;
		c->xi = d.xm;
		c->yi = d.ym;
	}
	else
	{
		c->d_mur = r.dy;
		c->num = d.ty;
		c->face = (r.dd < 90 || r.dd > 270) ? 0 : 2;
		c->xi = d.am;
		c->yi = d.bm;
	}
}

void	find_d(t_ray r, t_perso *p, t_map *m, t_column *c)
{
	t_dist	d;

	d.xm = (int)(p->pos_x / TS + r.cfxa) * TS;
	d.ym = r.coef * d.xm + p->pos_y - r.coef * p->pos_x;
	d.ya = TS * tanf(r.a / 180 * PI);
	while (!(d.tx = is_wall(d.xm, d.ym, m, r.cfxd)))
	{
		d.xm += r.cfxb * TS;
		d.ym += r.cfxc * d.ya;
	}
	r.dx = hypotf((float)(p->pos_x) - d.xm, (float)(p->pos_y) - d.ym);
	d.bm = (int)(p->pos_y / TS + r.cfya) * TS;
	d.am = (d.bm - (p->pos_y - r.coef * p->pos_x)) / r.coef;
	d.xa = TS / tanf(r.a / 180 * PI);
	while (!(d.ty = is_wall(d.am, d.bm, m, r.cfyd)))
	{
		d.am += r.cfyb * d.xa;
		d.bm += r.cfyc * TS;
	}
	r.dy = hypotf((float)(p->pos_x) - d.am, (float)(p->pos_y) - d.bm);
	get_all(c, d, r);
}

void	raycast2(float d, t_perso *p, t_map *m, t_column *c)
{
	t_ray	r;

	r.dd = d;
	r.coef = cosf(d / 180 * PI) / sinf(d / 180 * PI);
	r.a = (d < 180) ? 90 - d : 270 - d;
	r.a = (d > 270 || (d > 90 && d < 180)) ? -r.a : r.a;
	r.cfxa = (d < 180) ? 1 : 0;
	r.cfxb = (d < 180) ? 1 : -1;
	r.cfxc = (d < 90 || d > 270) ? 1 : -1;
	r.cfxd = (d < 180) ? 6 : 3;
	r.cfya = (d < 90 || d > 270) ? 1 : 0;
	r.cfyb = (d < 180) ? 1 : -1;
	r.cfyc = (d < 90 || d > 270) ? 1 : -1;
	r.cfyd = (d < 90 || d > 270) ? 6 : 4;
	find_d(r, p, m, c);
}
