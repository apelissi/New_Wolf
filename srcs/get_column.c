/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:45:55 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/21 17:38:37 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	get_column(t_column *c, float x_touch, float y_touch)
{
	float		w_r;
	float		w_l;
	float		w_d;
	float		w_u;

	w_u = TS * (int)(y_touch / TS);
	w_d = TS * ((int)(y_touch / TS) + 1);
	w_l = TS * (int)(x_touch / TS);
	w_r = TS * ((int)(x_touch / TS) + 1);
	c->face = -1;
	if (fabs(y_touch - w_u) <= 1)
		c->face = 0;
	if (fabs(y_touch - w_d) <= 1)
		c->face = (c->face == -1) ? 1 : c->old_face;
	if (fabs(x_touch - w_r) <= 1)
		c->face = (c->face == -1) ? 2 : c->old_face;
	if (fabs(x_touch - w_l) <= 1)
		c->face = (c->face == -1) ? 3 : c->old_face;
	if (c->face == 0 && !(int)(y_touch / TS))
		c->face = 1;
	if (c->face == 3 && !(int)(x_touch / TS))
		c->face = 2;
	c->old_face = c->face;
}
