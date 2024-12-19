/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/19 17:48:54 by vlopatin         ###   ########.fr       */
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
	map->width = 10;
	map->height = 6;
	map->size = map->width * map->height;
	map->points = malloc(map->size * sizeof(Point));
	while (y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->points[i].x = x;
			map->points[i].y = y;
			map->points[i++].z = 0; //make function to get height later
		}
		y++;
	}
}
void	define_angles(Angle *an)
{
	an->angle_x = atan(sqrt(1.0 / 2.0));
	an->angle_y = atan(sqrt(1.0 / 2.0));
	an->angle_z = M_PI/8;
}

