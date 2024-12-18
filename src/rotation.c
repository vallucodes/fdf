/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:46:23 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/18 16:04:08 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_X(Map *map)
{
	int i;
	int temp;
	double theta = atan(sqrt(1.0 / 2.0));
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

void	rotation_Y(Map *map)
{
	int i;
	int temp;
	double theta = atan(sqrt(1.0 / 2.0));
	// double theta = 0.1;
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

void	rotation_Z(Map *map)
{
	int i;
	int temp;
	double theta = M_PI/6;
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
void	scale(Map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		map->points[i].x *= SCALE;
		map->points[i].y *= SCALE;
		i++;
	}
}
