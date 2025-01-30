/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:44:11 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/29 11:58:28 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float	calc_interval(t_map *map)
{
	float	interval;

	interval = ft_minf(WIDTH / map->width, HEIGHT / map->height) / 2;
	interval = ft_maxf(1.5, interval);
	return (interval);
}

static void	set_color(t_map *map, char *arr, int *j, int *c)
{
	if (arr[(*j)] == ',' && arr[(*j) + 1] == '0')
	{
		(*j) += 3;
		map->original[(*c)].color = ft_atoi_base(&arr[(*j)], 16);
	}
	else
		map->original[(*c)].color = 0;
}

void	parse_row(t_map *map, char *arr, int *c)
{
	int		j;
	float	intrv;

	j = 0;
	intrv = calc_interval(map);
	while (arr[j] && arr[j] != '\n')
	{
		map->original[*c].z = ft_atoi_base(&arr[j], 10) * intrv / 2;
		map->original[*c].x = ((*c) % map->width) * intrv - \
		map->width / 2 * intrv;
		map->original[*c].y = ((*c) / map->width) * intrv - \
		map->height / 2 * intrv;
		while (ft_isspace(arr[j]))
			j++;
		while (arr[j] == '-' || ft_isdigit(arr[j]))
			j++;
		set_color(map, arr, &j, c);
		while (ft_isalnum(arr[j]))
			j++;
		while (ft_isspace(arr[j]))
			j++;
		(*c)++;
	}
}
