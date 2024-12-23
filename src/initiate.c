/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/23 13:18:43 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	populate_map(Map *map)
{
	int x;
	int y;
	int i;

	y = -1;
	i = 0;
	map->width = 20;
	map->height = 20;
	map->size = map->width * map->height;
	map->points = malloc(map->size * sizeof(Point));
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->points[i].x = x;
			map->points[i].y = y;
			if (i % 11 == 0)
			{
				map->points[i++].z = 1; //make function to get height later
				// map->points[i++].elevated = 1;
			}
			else
				map->points[i++].z = 0;
		}
	}
}
void	define_angles(Angle *an)
{
	an->angle_x = atan(sqrt(1.0 / 2.0));
	an->angle_y = atan(sqrt(1.0 / 2.0));
	an->angle_z = M_PI/5;
}

// void	define_colors(Colors *cl)
// {
// 	cl->non_elevated = 0xFFFF0000;
// 	cl->elevated = 0xFF00FF00;
// }

