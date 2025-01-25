/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/24 14:30:12 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	initiate_values_map(t_map *map)
{
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->z_scale = 1;
	map->cl.non_elevated = 0xFF240F4B;
	map->cl.elevated = 0xFF2E3D0B;
	map->cl.background = 0xFF67C0FF;
	map->x_offset = 0;
	map->y_offset = 0;
	map->zoom = 1;
	map->original = NULL;
	map->new2d = NULL;
}

