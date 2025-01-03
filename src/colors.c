/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:08:58 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/03 15:45:38 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
typedef float (*PointAccessor)(Point *point);


static int	is_all_set(Map *map)
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

float	get_x(Point *point)
{
	return (point->x);
}

float	get_y(Point *point)
{
	return (point->y);
}

float	get_z(Point *point)
{
	return (point->z);
}

int	find_lowest(Point *points, int size, PointAccessor accessor)
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

int	find_highest(Point *points, int size, PointAccessor accessor)
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

static void	write_colors(Map *map, int low, int high, Colors *cl)
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

void	set_colors(Map *map, Colors *cl)
{
	int			lowest;
	int			highest;

	lowest = map->points[0].z;
	highest = map->points[0].z;
	if(is_all_set(map))
		return ;
	lowest = find_lowest(map->points, map->size, get_z);
	highest = find_highest(map->points, map->size, get_z);
	printf("high: %i\n", highest);
	printf("low: %i\n", lowest);
	write_colors(map, lowest, highest, cl);
}
