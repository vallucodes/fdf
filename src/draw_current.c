/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_current.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:20 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/23 12:35:25 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_points(Draw *start_end, Point *point1, Point *point2)
{
	start_end->x1 = point1->x;
	start_end->y1 = point1->y;
	start_end->z1 = point1->z;
	start_end->x2 = point2->x;
	start_end->y2 = point2->y;
	start_end->z2 = point2->z;
}

void	draw_current_state(int32_t *pixels, mlx_image_t* img, Map *map)
{
	int		i;
	int		j;
	int		c;
	Draw	start_end;

	j = -1;
	c = 0;
	while(++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (i < (map->width - 1))
			{
				initialize_points(&start_end, &map->points[c], &map->points[c + 1]);
				draw_line(pixels, img->width, start_end, 0xFF00FF00);
			}
			if (j < (map->height - 1))
			{
				initialize_points(&start_end, &map->points[c], &map->points[c + map->width]);
				draw_line(pixels, img->width, start_end, 0xFF00FF00);
			}
			c++;
		}
	}
}
