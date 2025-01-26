/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:49:43 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/26 11:28:34 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void display_old_map(t_map *map)
{
    int i;
    t_point *point;

    printf("ORIGINAL:\n");
    printf("Rows: %d, Columns: %d\n", map->width, map->height);
    // printf("Height Range: Low = %.2d, High = %.2d\n", map->low, map->high);
    printf("=========================================\n");

    for (i = 0; i < map->size; i++)
    {
		point = &(map->original[i]);
		printf("Point[%d]: x=%.2f, y=%.2f, z=%.2f, color=0x%x\n",
				i, point->x, point->y, point->z, point->color);
    }
	// printf("angles 1: %f, 2: %f, 3: %f\n", map->xrotate, map->yrotate, map->zrotate);
    printf("=========================================\n");
}

void display_new_map(t_map *map)
{
    int i;
    t_point *point;

    printf("NEW MAP:\n");
    printf("Rows: %d, Columns: %d\n", map->width, map->height);
    // printf("Height Range: Low = %.2d, High = %.2d\n", map->low, map->high);
    printf("=========================================\n");

    for (i = 0; i < map->size; i++)
    {
		point = &(map->new2d[i]);
		printf("Point[%d]: x=%.2f, y=%.2f, z=%.2f, color=0x%x\n",
				i, point->x, point->y, point->z, point->color);
    }
	// printf("angles 1: %f, 2: %f, 3: %f\n", map->xrotate, map->yrotate, map->zrotate);
    printf("=========================================\n");
}

// void	ft_round(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (i < map->size)
// 	{
// 		map->new2d[i].x = roundf(map->new2d[i].x);
// 		map->new2d[i].y = roundf(map->new2d[i].y);
// 		map->new2d[i].z = roundf(map->new2d[i].z);
// 		i++;
// 	}
// }

void	copy_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->new2d[i].x = map->original[i].x;
		map->new2d[i].y = map->original[i].y;
		map->new2d[i].z = map->original[i].z;
		map->new2d[i].color = map->original[i].color;
		i++;
	}
}


