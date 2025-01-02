/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/02 16:42:31 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_elevation(Map *map)
{
	int x;
	int y;
	int i;

	y = -1;
	i = 0;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->points[i].z != 0)
				map->points[i++].elevated = 1;
			else
				map->points[i++].elevated = 0;
		}
	}
}
void	define_angles(Angle *an)
{
	an->angle_x = atan(sqrt(1.0 / 2.0));
	an->angle_y = atan(sqrt(1.0 / 2.0));
	an->angle_z = M_PI/5;
}

void	define_colors(Colors *cl)
{
	cl->non_elevated = 0xFF;
	cl->elevated = 0xFF00;
}

