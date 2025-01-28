/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/28 11:29:34 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	initiate_values_map(t_map *map)
{
	map->alpha_x = 1;
	map->alpha_z = M_PI / 4;
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->z_scale = 1;
	// map->cl.non_elevated = 0xFF240F4B;
	map->cl.non_elevated = 0xFF0000BB;
	map->cl.elevated = 0xFF7A7A1E;
	map->cl.background = 0xFFC067BB;
	map->x_offset = 0;
	map->y_offset = 0;
	map->zoom = 1;
}

