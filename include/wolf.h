/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:27:55 by apelissi          #+#    #+#             */
/*   Updated: 2019/02/20 16:37:03 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef WOLF_H
#		define WOLF_H

#include "color.h"
#include "math.h"
#include "keyboard.h"
#include "../Libft/libft.h"
#include "../miniLibX/mlx.h"

#define VD 5
#define VR 4
#define TS 100
#define PI 3.14159265359

typedef	struct		s_map{
	char			**grid;
	int				*data_map;
	void			*img_map;
	int				t_x;
	int				t_y;
	int				img_x;
	int				img_y;
}					t_map;

typedef struct		s_column{
	float			d_mur;
	int				num;
	int				face;
	float			xi;
	float			yi;
}					t_column;

typedef	struct		s_perso{
	int				x_map;
	int				y_map;
	int				pos_x;
	int				pos_y;
	int				mv_x;
	int				mv_y;
	int				mv_r;
	int				angle;
	int				pos_z;
}					t_perso;

typedef struct		s_env{
	int				f;
	t_perso			*pe;
	t_map			*map;
	t_column		*c;
	void			*ptr;
	void			*win;
	int				*data;
	int				win_x;
	int				win_y;
	void			*img;
	int				psi;
	int				p;
	int				pm;
}					t_env;

typedef	struct		s_ray{
	float			coef;
	float			a;
	float			dd;
	float			dx;
	float			dy;
	int				cfxa;
	int				cfxb;
	int				cfxc;
	int				cfxd;
	int				cfya;
	int				cfyb;
	int				cfyc;
	int				cfyd;
}					t_ray;

typedef	struct		s_dist{
	float			xm;
	float			ym;
	float			ya;
	int				tx;
	float			am;
	float			bm;
	float			xa;
	int				ty;
}					t_dist;

typedef struct		s_render{
	int				nx;
	int				nz;
	int				ny;
	int				z;
}					t_render;

int					ft_mlx(t_env *e);
int					deal_key(int key, t_env *te);
int					get_map(t_map *map, int fd);
void				ft_is_perso(char **grid);
void				get_grid(t_env *e);
void				get_perso(t_env *e, t_perso *p);
int					key_press(int k, t_env *e);
int					key_release(int k, t_env *e);
int					expose_hook(t_env *e);
void				erase_player(t_env *e, int y_map, int x_map);
void				get_view(t_env *e);
void				ft_clean(t_env *e);
void				get_column(t_column *c, float x_touch, float y_touch);
int					ft_exit(int i);
int					ft_click_exit(void);
void				ft_init_texture(t_env *e);
void				raycast(float d, t_perso *p, t_map *m, t_column *c);

#		endif
