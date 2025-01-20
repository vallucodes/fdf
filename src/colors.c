/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:08:58 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/20 11:28:44 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
typedef float (*PointAccessor)(t_point *point);


static int	is_all_set(t_map *map)
{
	int i;

	i = 0;
	while(i < map->size)
	{
		if (map->points[i].color == 0)
			return (0);
		i++;
	}
	return (1);
}

float	get_x(t_point *point)
{
	return (point->x);
}

float	get_y(t_point *point)
{
	return (point->y);
}

float	get_z(t_point *point)
{
	return (point->z);
}

int	find_lowest(t_point *points, int size, PointAccessor accessor)
{
	int		i;
	float	nb;

	i = 1;
	nb = accessor(&points[0]);
	while(i < size)
	{
		if (nb > accessor(&points[i]))
			nb = accessor(&points[i]);
		i++;
	}
	return (nb);
}

int	find_highest(t_point *points, int size, PointAccessor accessor)
{
	int		i;
	float	nb;

	i = 1;
	nb = accessor(&points[0]);
	while(i < size)
	{
		if (nb < accessor(&points[i]))
			nb = accessor(&points[i]);
		i++;
	}
	return (nb);
}

static void	write_colors(t_map *map, int low, int high, t_colors *cl)
{
	int			i;
	float		t;
	uint32_t	color;

	i = 0;
	while (i < map->size)
	{
		t = (map->points[i].z - low) / (high - low);
		color = interpolate_color(cl->non_elevated, cl->elevated, t);
		map->points[i].color = color;
		i++;
	}
}

void	set_colors(t_map *map, t_colors *cl)
{
	int			lowest;
	int			highest;

	lowest = map->points[0].z;
	highest = map->points[0].z;
	if(is_all_set(map))
		return ;
	lowest = find_lowest(map->points, map->size, get_z);
	highest = find_highest(map->points, map->size, get_z);
	// printf("high: %i\n", highest);
	// printf("low: %i\n", lowest);
	write_colors(map, lowest, highest, cl);
}
