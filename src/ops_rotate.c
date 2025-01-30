/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:46:23 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/29 11:16:13 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotation_x(t_map *map, float theta)
{
	int		i;
	float	temp;

	i = 0;
	while (i < map->size)
	{
		temp = map->new2d[i].y;
		map->new2d[i].y = (temp * cos(theta) - map->new2d[i].z * sin(theta));
		map->new2d[i].z = (temp * sin(theta) + map->new2d[i].z * cos(theta));
		i++;
	}
}

void	rotation_y(t_map *map, float theta)
{
	int		i;
	float	temp;

	i = 0;
	while (i < map->size)
	{
		temp = map->new2d[i].x;
		map->new2d[i].x = (temp * cos(theta) + map->new2d[i].z * sin(theta));
		map->new2d[i].z = (temp * -sin(theta) + map->new2d[i].z * cos(theta));
		i++;
	}
}

void	rotation_z(t_map *map, float theta)
{
	int		i;
	float	temp;

	i = 0;
	while (i < map->size)
	{
		temp = map->new2d[i].x;
		map->new2d[i].x = (temp * cos(theta) - map->new2d[i].y * sin(theta));
		map->new2d[i].y = (temp * sin(theta) + map->new2d[i].y * cos(theta));
		i++;
	}
}

void	special_view(t_map *map, float alpha_x, float alpha_z)
{
	rotation_z(map, alpha_z);
	rotation_x(map, alpha_x);
}
