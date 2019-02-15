/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:19:06 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/12 12:47:07 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int	line_handler(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] < '0' || line[i] > '9')
		i++;
	map->t_x = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	map->t_y = ft_atoi(&line[i]);
	if (map->t_x <= 0 || map->t_y <= 0)
		return (0);
	return (1);
}

int	get_dim(t_map *map, int fd)
{
	char	*line;
	char	*temp;
	char	buff[2];

	line = NULL;
	buff[0] = '*';
	while (read(fd, buff, 1) > 0 && buff[0] != '\n')
	{
		temp = line;
		buff[1] = '\0';
		if (!(line = ft_sbtlejoin(line, buff)))
			return (0);
		if (temp)
			free(temp);
	}
	if (buff[0] != '\n')
		return (0);
	if (!(line_handler(map, line)))
		return (0);
	free(line);
	return (1);
}

int	recup_grid(t_map *map, int fd)
{
	int	i;

	if (!(map->grid = (char **)malloc((map->t_y + 1) * sizeof(char *))))
		return (0);
	i = 0;
	while (i < map->t_y)
	{
		if (!(map->grid[i] = (char *)malloc((map->t_x + 1) * sizeof(char))))
			return (0);
		if (read(fd, map->grid[i], map->t_x + 1) < map->t_x + 1)
			return (0);
		map->grid[i][map->t_x] = '\0';
		i++;
	}
	map->grid[i] = NULL;
	return (1);
}

int	get_map(t_map *map, int fd)
{
	if (!(get_dim(map, fd)))
		return (0);
	if (!(recup_grid(map, fd)))
		return (0);
	return (1);
}
