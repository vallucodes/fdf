/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_current.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:22:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/29 12:00:47 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	init_pts(t_draw *ln_ends, t_point *point1, t_point *point2)
{
	ln_ends->x1 = point1->x;
	ln_ends->y1 = point1->y;
	ln_ends->z1 = point1->z;
	ln_ends->c1 = point1->color;
	ln_ends->x2 = point2->x;
	ln_ends->y2 = point2->y;
	ln_ends->z2 = point2->z;
	ln_ends->c2 = point2->color;
}

void	draw_current_state(int32_t *pixels, mlx_image_t *img, t_map *map)
{
	int		i;
	int		j;
	int		c;
	t_draw	ln_ends;

	j = -1;
	c = 0;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			if (i < (map->width - 1))
			{
				init_pts(&ln_ends, &map->new2d[c], &map->new2d[c + 1]);
				draw_line(pixels, img->width, ln_ends);
			}
			if (j < (map->height - 1))
			{
				init_pts(&ln_ends, &map->new2d[c], &map->new2d[c + map->width]);
				draw_line(pixels, img->width, ln_ends);
			}
			c++;
		}
	}
}
