/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_current.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:20 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/23 14:38:53 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initialize_points(Draw *start_end, Point *point1, Point *point2, Colors *cl)
{
	start_end->x1 = point1->x;
	start_end->y1 = point1->y;
	start_end->z1 = point1->z;
	start_end->x2 = point2->x;
	start_end->y2 = point2->y;
	start_end->z2 = point2->z;
	if (point1->elevated == 1)
	{
		start_end->c1 = cl->non_elevated;
		start_end->c2 = cl->elevated;
	}
	else if (point2->elevated == 1)
	{
		start_end->c1 = cl->elevated;
		start_end->c2 = cl->non_elevated;
	}
	else
	{
		start_end->c1 = cl->elevated;
		start_end->c2 = cl->elevated;
	}
}

void	draw_current_state(int32_t *pixels, mlx_image_t* img, Map *map, Colors *cl)
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
				initialize_points(&start_end, &map->points[c], &map->points[c + 1] , cl);
				// printf("point1->elevated: %i, point2->elevated: %i,", map->points[c].elevated, map->points[c + 1].elevated)
				draw_line(pixels, img->width, start_end);
			}
			if (j < (map->height - 1))
			{
				initialize_points(&start_end, &map->points[c], &map->points[c + map->width], cl);
				draw_line(pixels, img->width, start_end);
			}
			c++;
		}
	}
}
