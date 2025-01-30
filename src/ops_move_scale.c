/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_move_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:46:23 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/29 11:01:17 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	apply_scale_z(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->new2d[i].z *= map->z_scale;
		i++;
	}
}

void	zoom(t_map *map)
{
	int	i;

	i = 0;
	if (map->zoom > 0)
	{
		while (i < map->size)
		{
			map->new2d[i].x *= map->zoom;
			map->new2d[i].y *= map->zoom;
			i++;
		}
	}
}

void	translate(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->new2d[i].x += WIDTH / 2;
		map->new2d[i].x += map->x_offset;
		map->new2d[i].y += HEIGHT / 2;
		map->new2d[i].y += map->y_offset;
		i++;
	}
}
