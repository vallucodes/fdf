/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:08:58 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/03 14:09:12 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int	find_lowest(Map *map)
{
	int		i;
	float	nb;

	i = 1;
	nb = map->points[0].z;
	while(i < map->size)
	{
		if (nb > map->points[i].z)
			nb = map->points[i].z;
		i++;
	}
	return (nb);
}

static int	find_highest(Map *map)
{
	int		i;
	float	nb;

	i = 1;
	nb = map->points[0].z;
	while(i < map->size)
	{
		if (nb < map->points[i].z)
			nb = map->points[i].z;
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
	lowest = find_lowest(map);
	highest = find_highest(map);
	printf("high: %i\n", highest);
	printf("low: %i\n", lowest);
	write_colors(map, lowest, highest, cl);
}
