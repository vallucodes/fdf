/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/20 16:28:58 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_elevation(t_map *map)
{
	int x;
	int y;
	int i;
	int bigger_side;

	y = -1;
	i = 0;
	if (map->width > map->height)
		bigger_side = map->width;
	else
		bigger_side = map->height;
	map->points[0].huge = 0;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			// printf("ratio: %f\n", map->points[i].z / bigger_side);
			if (map->points[i].z < 0)
				map->points[i].z *= -1;
			if (map->points[i].z / bigger_side > 3)
			{
				map->points[0].huge = 1;
			}
			i++;
		}
	}
}
void	define_angles(t_angle *an)
{
	an->angle_x = atan(sqrt(1.0 / 2.0));
	an->angle_y = atan(sqrt(1.0 / 2.0));
	an->angle_z = M_PI/5;
}

// 0xAABBGGRR
void	define_colors(t_colors *cl)
{
	cl->non_elevated = 0xFF;
	cl->elevated = 0xFF00;
	cl->background = 0x20FF0000;
}

