/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:49:43 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/23 12:31:54 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void display_draw_state(t_draw *start_end)
{
    printf("Current State of t_draw:\n");
    printf("=========================\n");
    printf("Point 1:\n");
    printf("  x1: %.2i\n", start_end->x1);
    printf("  y1: %.2i\n", start_end->y1);
    printf("  z1: %.2i\n", start_end->z1);
    printf("  c1 (color): 0x%x\n", start_end->c1);
    printf("-------------------------\n");
    printf("Point 2:\n");
    printf("  x2: %.2i\n", start_end->x2);
    printf("  y2: %.2i\n", start_end->y2);
    printf("  z2: %.2i\n", start_end->z2);
    printf("  c2 (color): 0x%x\n", start_end->c2);
    printf("=========================\n");
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

void	ft_round(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->new2d[i].x = roundf(map->new2d[i].x);
		map->new2d[i].y = roundf(map->new2d[i].y);
		map->new2d[i].z = roundf(map->new2d[i].z);
		i++;
	}
}

void	print_result(t_map *map)
{
	int i = 0;
	while (i < map->size)
	{
		printf("i: %i, ", i);
		printf("xyz color: %f ", map->new2d[i].x);
		printf("%f ", map->new2d[i].y);
		printf("%f ", map->new2d[i].z);
		printf("%X ", map->new2d[i].color);
		i++;
	}
	printf("----------------------------------------------\n");
}


