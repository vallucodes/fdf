/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_current.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/25 16:01:07 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	initialize_points(t_draw *start_end, t_point *point1, t_point *point2)
{
	start_end->x1 = point1->x;
	start_end->y1 = point1->y;
	start_end->z1 = point1->z;
	start_end->c1 = point1->color;
	start_end->x2 = point2->x;
	start_end->y2 = point2->y;
	start_end->z2 = point2->z;
	start_end->c2 = point2->color;
}

void	reset_background(int32_t* pixels, t_fdf *fdf)
{
	int i = 0;

	while (i < WIDTH * HEIGHT)
	{
		pixels[i] = fdf->map->cl.background;
		i++;
	}
}

void	draw(t_map *map)
{
	copy_map(map);
	scale_z(map);
	isometric_view(map);
	rotation_X(map, map->angle_x);
	rotation_Y(map, map->angle_y);
	rotation_Z(map, map->angle_z);
	scale(map);
	translate(map);
	set_colors(map);
}

void	draw_current_state(int32_t *pixels, mlx_image_t* img, t_map *map)
{
	int		i;
	int		j;
	int		c;
	t_draw	start_end;

	j = -1;
	c = 0;
	while(++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (i < (map->width - 1))
			{
				initialize_points(&start_end, &map->new2d[c], &map->new2d[c + 1]);
				draw_line(pixels, img->width, start_end);
			}
			if (j < (map->height - 1))
			{
				initialize_points(&start_end, &map->new2d[c], &map->new2d[c + map->width]);
				draw_line(pixels, img->width, start_end);
			}
			c++;
		}
	}
}
