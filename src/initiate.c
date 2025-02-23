/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/23 12:39:48 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	auto_center_y(t_map *map)
{
	int		i;
	float	y_lowest;
	float	y_highest;

	i = 1;
	y_lowest = map->new2d[0].y;
	while (i < map->size)
	{
		if (y_lowest > map->new2d[i].y)
			y_lowest = map->new2d[i].y;
		i++;
	}
	i = 1;
	y_highest = map->new2d[0].y;
	while (i < map->size)
	{
		if (y_highest < map->new2d[i].y)
			y_highest = map->new2d[i].y;
		i++;
	}
	map->y_offset = (HEIGHT / 2) - (y_highest + y_lowest) / 2;
}

void	set_z_scale(t_map *map)
{
	float	min;
	float	max;
	float	dz;

	min = find_lowest(map->original, map->size);
	max = find_highest(map->original, map->size);
	dz = max - min;
	while (dz > HEIGHT * 0.3)
	{
		map->z_scale *= 0.95;
		dz *= 0.9;
	}
}

void	initiate_values_map(t_map *map)
{
	map->alpha_x = 1;
	map->alpha_z = M_PI / 4;
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->z_scale = 1;
	map->cl.non_elevated = 0xFF0000BB;
	map->cl.elevated = 0xFF7A7A1E;
	map->cl.background = 0xFFC067BB;
	map->x_offset = 0;
	map->y_offset = 0;
	map->zoom = 1;
}

void	dimetric_view(t_map *map)
{
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->alpha_x = 1;
	map->alpha_z = M_PI / 4;
}

void	isometric_view(t_map *map)
{
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->alpha_x = atan(1 / sqrt(2));
	map->alpha_z = M_PI / 4;
}
