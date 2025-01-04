/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:39:46 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/04 12:40:55 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	align_to_center(Map *map)
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
