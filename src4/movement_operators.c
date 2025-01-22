/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_operators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:46:23 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/20 13:22:59 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_X(t_map *map, double theta)
{
	int i;
	int temp;

	temp = 0;
	i = 0;
	while (i < map->size)
	{
		temp = map->points[i].y;
		map->points[i].y = (temp * cos(theta) - map->points[i].z * sin(theta));
		map->points[i].z = (temp * sin(theta) + map->points[i].z * cos(theta));
		i++;
	}
}

void	rotation_Y(t_map *map, double theta)
{
	int i;
	int temp;

	temp = 0;
	i = 0;
	while (i < map->size)
	{
		temp = map->points[i].x;
		map->points[i].x = (temp * cos(theta) + map->points[i].z * -sin(theta));
		map->points[i].z = (temp * sin(theta) + map->points[i].z * cos(theta));
		i++;
	}
}

void	rotation_Z(t_map *map, double theta)
{
	int i;
	int temp;

	temp = 0;
	i = 0;
	while (i < map->size)
	{
		temp = map->points[i].x;
		map->points[i].x = (temp * cos(theta) - map->points[i].y * sin(theta));
		map->points[i].y = (temp * sin(theta) + map->points[i].y * cos(theta));
		i++;
	}
}
void	scale(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		map->points[i].x *= SCALE;
		map->points[i].y *= SCALE;
		map->points[i].z *= SCALE / 2;
		i++;
	}
}

void	translate(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->points[i].x += WIDTH / 2;
		map->points[i].y += HEIGHT / 3;
		i++;
	}
}
