/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:08:58 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/24 13:40:10 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

typedef float (*PointAccessor)(t_point *point);

static int	is_all_set(t_map *map)
{
	int i;

	i = 0;
	while(i < map->size)
	{
		if (map->original[i].color == 0)
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

int	find_lowest(t_point *original, int size, PointAccessor accessor)
{
	int		i;
	float	nb;

	i = 1;
	nb = accessor(&original[0]);
	while(i < size)
	{
		if (nb > accessor(&original[i]))
			nb = accessor(&original[i]);
		i++;
	}
	return (nb);
}

int	find_highest(t_point *original, int size, PointAccessor accessor)
{
	int		i;
	float	nb;

	i = 1;
	nb = accessor(&original[0]);
	while(i < size)
	{
		if (nb < accessor(&original[i]))
			nb = accessor(&original[i]);
		i++;
	}
	return (nb);
}

static void	write_colors(t_map *map, int low, int high)
{
	int			i;
	float		t;
	uint32_t	color;

	i = 0;
	while (i < map->size)
	{
		t = (map->original[i].z - low) / (high - low);
		color = interpolate_color(map->cl.non_elevated, map->cl.elevated, t);
		map->new2d[i].color = color;
		i++;
	}
}

void	set_colors(t_map *map)
{
	int			lowest;
	int			highest;

	lowest = map->original[0].z;
	highest = map->original[0].z;
	if(is_all_set(map))
		return ;
	lowest = find_lowest(map->original, map->size, get_z);
	highest = find_highest(map->original, map->size, get_z);
	write_colors(map, lowest, highest);
}
