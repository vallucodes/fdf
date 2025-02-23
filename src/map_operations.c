/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:49:43 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/23 12:24:51 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	copy_map(t_map *map)
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

void	reset_background(t_fdf *fdf)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < fdf->img->height)
	{
		j = 0;
		while (j < fdf->img->width)
		{
			mlx_put_pixel(fdf->img, j, i, fdf->map->cl.background);
			j++;
		}
		i++;
	}
}

void	do_operations(t_map *map)
{
	copy_map(map);
	apply_scale_z(map);
	special_view(map, map->alpha_x, map->alpha_z);
	rotation_x(map, map->angle_x);
	rotation_y(map, map->angle_y);
	rotation_z(map, map->angle_z);
	zoom(map);
	translate(map);
	set_colors(map);
}
