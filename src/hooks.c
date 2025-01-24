/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:35:32 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/24 14:39:35 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (ydelta > 0)
		fdf->map->zoom *= 1.05;
	else
		fdf->map->zoom *= 0.95;
	xdelta++;
}

void	ft_hook_rotate(void *param)
{
	t_fdf	*fdf;
	int		sign;

	fdf = (t_fdf *)param;
	sign = 0;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_SHIFT))
		sign = -1;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_CONTROL))
		sign = 1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_J))
		fdf->map->z_scale += sign * 0.2;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		fdf->map->angle_x += sign * 0.03;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Y))
		fdf->map->angle_y += sign * 0.03;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		fdf->map->angle_z += sign * 0.03;
}

void	ft_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->map->x_offset -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->map->x_offset += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->map->y_offset += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->map->y_offset -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_R))
		ft_scrollhook(0, 1, param);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_T))
		ft_scrollhook(0, -1, param);
}

void	draw_hook(void *param)
{
	t_fdf *fdf = (t_fdf *)param;
	reset_background((int32_t*)fdf->img->pixels, fdf);
	draw(fdf->map);
	draw_current_state((int32_t*)fdf->img->pixels, fdf->img, fdf->map);
}
