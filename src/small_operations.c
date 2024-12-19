/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:49:43 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/19 17:50:01 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_round(Map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->points[i].x = roundf(map->points[i].x);
		map->points[i].y = roundf(map->points[i].y);
		map->points[i].z = roundf(map->points[i].z);
		i++;
	}
}

void	print_result(Map *map)
{
	int i = 0;
	while (i < map->size)
	{
		printf("i: %i, ", i);
		printf("xyz: %f ", map->points[i].x);
		printf("%f ", map->points[i].y);
		printf("%f\n", map->points[i].z);
		i++;
	}
	printf("----------------------------------------------\n");
}


