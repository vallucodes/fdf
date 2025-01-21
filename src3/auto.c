/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:39:46 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/21 09:54:07 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	align_to_center(t_map *map)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	move_x;
	int	move_y;
	int	i;

	x2 = find_highest(map->points, map->size, get_x);
	x1 = find_lowest(map->points, map->size, get_x);
	y2 = find_highest(map->points, map->size, get_y);
	y1 = find_lowest(map->points, map->size, get_y);

	move_x = WIDTH/2 - ((x2 + x1) / 2);
	move_y = HEIGHT/2 - ((y2 + y1) / 2);
	i = 0;
	while (i < map->size)
	{
		map->points[i].x += move_x;
		map->points[i].y += move_y;
		i++;
	}
}

void	automatic_scale(t_map *map)
{
	float x1;
	float y1;
	float x2;
	float y2;
	// float z1;
	// float z2;
	float dx;
	float dy;
	// float dz;
	float SCALE_X;
	float SCALE_Y;
	float SCA;
	int i;

	x2 = find_highest(map->points, map->size, get_x);
	x1 = find_lowest(map->points, map->size, get_x);
	y2 = find_highest(map->points, map->size, get_y);
	y1 = find_lowest(map->points, map->size, get_y);
	// z2 = find_highest(map->points, map->size, get_z);
	// z1 = find_lowest(map->points, map->size, get_z);
	// dz = z2 - z1;
	dx = x2 - x1;
	dy = y2 - y1;

	// printf("dx dy dz: %f, %f, %f\n", dx, dy, dz);
	SCALE_Y = (HEIGHT - 100) / dy;
	SCALE_X = (WIDTH - 100) / dx;
	if (SCALE_X < SCALE_Y)
		SCA = SCALE_X;
	else
		SCA = SCALE_Y;
	// printf("SCA: %f\n", SCA);
	i = 0;

	i = 0;
	while (i < map->size)
	{
		map->points[i].x *= SCA;
		map->points[i].y *= SCA;
		map->points[i].z *= SCA;
		i++;
	}
}
