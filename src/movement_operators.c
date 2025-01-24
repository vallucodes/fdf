/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_operators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:46:23 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/24 13:43:00 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotation_X(t_map *map, float theta)
{
	int i;
	float temp;

	i = 0;
	while (i < map->size)
	{
		temp = map->new2d[i].y;
		map->new2d[i].y = (temp * cos(theta) - map->new2d[i].z * sin(theta));
		map->new2d[i].z = (temp * sin(theta) + map->new2d[i].z * cos(theta));
		i++;
	}
}

void	rotation_Y(t_map *map, float theta)
{
	int i;
	float temp;

	i = 0;
	while (i < map->size)
	{
		temp = map->new2d[i].x;
		map->new2d[i].x = (temp * cos(theta) + map->new2d[i].z * sin(theta));
		map->new2d[i].z = (temp * -sin(theta) + map->new2d[i].z * cos(theta));
		i++;
	}
}

void	rotation_Z(t_map *map, float theta)
{
	int i;
	float temp;

	i = 0;
	while (i < map->size)
	{
		temp = map->new2d[i].x;
		map->new2d[i].x = (temp * cos(theta) - map->new2d[i].y * sin(theta));
		map->new2d[i].y = (temp * sin(theta) + map->new2d[i].y * cos(theta));
		i++;
	}
}

void	isometric_view(t_map *map)
{
	rotation_Z(map, M_PI / 4);
	rotation_X(map, atan(1 / sqrt(2)));
}

void	scale_z(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		map->new2d[i].z *= map->z_scale;
		i++;
	}
}

void	scale(t_map *map)
{
	int i;

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
