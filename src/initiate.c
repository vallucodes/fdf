/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/23 12:04:36 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	populate_map(Map *map)
{
	int x;
	int y;
	int i;

	x = -1;
	y = 0;
	i = 0;
	map->width = 20;
	map->height = 20;
	map->size = map->width * map->height;
	map->points = malloc(map->size * sizeof(Point));
	while (y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->points[i].x = x;
			map->points[i].y = y;
			if (i % 11 == 0)
				map->points[i++].z = 1; //make function to get height late
			else
				map->points[i++].z = 0;
		}
		y++;
	}
}
void	define_angles(Angle *an)
{
	an->angle_x = atan(sqrt(1.0 / 2.0));
	an->angle_y = atan(sqrt(1.0 / 2.0));
	an->angle_z = M_PI/5;
}

