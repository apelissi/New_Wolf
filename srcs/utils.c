/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:46 by apelissi          #+#    #+#             */
/*   Updated: 2019/01/21 15:24:32 by maxsimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		ft_exit(int i)
{
	if (i == 1)
		ft_putstr("Invalid Map\n");
	if (i == 2)
		ft_putstr("usage : ./Wolf3D <filename>\n");
	if (i == 3)
		ft_putstr("Esc Pressed\n");
	if (i == 4)
		ft_putstr("Invalid Fd\n");
	if (i == 5)
		ft_putstr("Texture error\n");
	exit(0);
}

int		ft_click_exit(void)
{
	ft_putstr("Red Cross\n");
	exit(0);
}

void	ft_is_perso(char **grid)
{
	int	i;
	int	j;
	int p;

	p = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '@')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		ft_exit(1);
}

void	ft_clean(t_env *e)
{
	e->f = 0;
	mlx_destroy_image(e->ptr, e->map->img_map);
}
