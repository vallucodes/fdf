/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/23 11:21:50 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	set_elevation(t_map *map)
// {
// 	int x;
// 	int y;
// 	int i;
// 	int bigger_side;

// 	y = -1;
// 	i = 0;
// 	if (map->width > map->height)
// 		bigger_side = map->width;
// 	else
// 		bigger_side = map->height;
// 	map->points[0].huge = 0;
// 	while (++y < map->height)
// 	{
// 		x = -1;
// 		while (++x < map->width)
// 		{
// 			// printf("ratio: %f\n", map->points[i].z / bigger_side);
// 			if (map->points[i].z < 0)
// 				map->points[i].z *= -1;
// 			if (map->points[i].z / bigger_side > 3)
// 			{
// 				map->points[0].huge = 1;
// 			}
// 			i++;
// 		}
// 	}
// }

// 0xAABBGGRR

