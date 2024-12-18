/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_current.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:20 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/18 15:23:20 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(int32_t *pixels, mlx_image_t* img, Point *point1, Point *point2)
{
	// Draw points;
	draw_line(pixels, img->width, point1->x, point1->y, point2->x, point2->y, 0xFF00FF00);
}

void	draw_current_state(int32_t *pixels, mlx_image_t* img, Map *map)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while(j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (i < (map->width - 1))
				draw(pixels, img, &map->points[c], &map->points[c + 1]);
			if (j < (map->height - 1))
				draw(pixels, img, &map->points[c], &map->points[c + map->width]);
			c++;
			i++;
		}
		j++;
	}
}
