/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:08:58 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/23 12:34:57 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	is_all_set(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		if (map->original[i].color == 0)
			return (0);
		i++;
	}
	return (1);
}

float	find_lowest(t_point *original, int size)
{
	int		i;
	float	nb;

	i = 1;
	nb = original[0].z;
	while (i < size)
	{
		if (nb > original[i].z)
			nb = original[i].z;
		i++;
	}
	return (nb);
}

float	find_highest(t_point *original, int size)
{
	int		i;
	float	nb;

	i = 1;
	nb = original[0].z;
	while (i < size)
	{
		if (nb < original[i].z)
			nb = original[i].z;
		i++;
	}
	return (nb);
}

static void	write_colors(t_map *map, float low, float high)
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
	float	lowest;
	float	highest;

	if (is_all_set(map))
		return ;
	lowest = map->original[0].z;
	highest = map->original[0].z;
	lowest = find_lowest(map->original, map->size);
	highest = find_highest(map->original, map->size);
	write_colors(map, lowest, highest);
}
