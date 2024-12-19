/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:46:23 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/19 17:54:00 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_X(Map *map, double theta)
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

void	rotation_Y(Map *map, double theta)
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

void	rotation_Z(Map *map, double theta)
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

void	translate(Map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->points[i].x += WIDTH / 2;
		map->points[i].y += HEIGHT / 8;
		i++;
	}
}
