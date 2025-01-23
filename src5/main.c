/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/23 12:35:39 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/fdf.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
// static void ft_hook(void* param)
// {
// 	t_map *map = (t_map *)param;

// 	printf("actual point: %f\n", map->original[0].x);
// }

void	reset_background(int32_t* pixels, t_fdf *fdf)
{
	int i = 0;

	while (i < WIDTH * HEIGHT)
	{
		pixels[i] = fdf->map->cl.background;
		i++;
	}
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf *fdf = (t_fdf *)param;
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
	{
		int i = 0;
		while (i < fdf->map->size)
		{
			fdf->map->original[i].x += 50;
			i++;
		}
	}
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
	{
		fdf->map->angle_x = 0.05;
		rotation_X(fdf->map, fdf->map->angle_x);
	}
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
	{
		fdf->map->angle_y = 0.05;
		rotation_Y(fdf->map, fdf->map->angle_y);
	}
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		fdf->map->angle_z = 0.05;
		rotation_Z(fdf->map, fdf->map->angle_z);
	}
}

void	draw(t_map *map)
{
	scale_z(map);
	rotation_X(map, map->angle_x);
	rotation_Y(map, map->angle_y);
	rotation_Z(map, map->angle_z);
	scale(map);
	translate(map);
	set_colors(map);
	ft_round(map);
}

void	draw_hook(void *param) // under work, trying to implement rotations
{
	t_fdf *fdf = (t_fdf *)param;
	reset_background((int32_t*)fdf->img->pixels, fdf);
	draw(fdf->map);
	draw_current_state((int32_t*)fdf->img->pixels, fdf->img, fdf->map);
}

void	initiate_values_map(t_map *map)
{
	map->angle_x = atan(sqrt(1.0 / 2.0));
	map->angle_y = atan(sqrt(1.0 / 2.0));
	map->angle_z = M_PI/5;
	map->z_scale = 1;
	map->cl.non_elevated = 0xFF;
	map->cl.elevated = 0xFF00;
	map->cl.background = 0xFF67C0FF;
	map->x_offset = 0;
	map->y_offset = 0;
	map->zoom = 1;
	map->original = NULL;
	map->new2d = NULL;
}

void	copy_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->new2d[i].x = map->original[i].x;
		map->new2d[i].y = map->original[i].y;
		map->new2d[i].z = map->original[i].z;
		map->new2d[i].color = map->original[i].color;
		i++;
	}
}

int32_t	main(int ac, char **av)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	t_fdf fdf;
	t_map map;

	fdf.map = &map;
	fdf.img = img;

	initiate_values_map(&map);
	if (ac == 2)
		map_parsing(&map, av[1]);
	copy_map(&map);
	draw(&map);

	int32_t* pixels = (int32_t*)img->pixels;

	// print_result(&map);

	draw_current_state(pixels, img, &map);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, &ft_hook, NULL);

	// mlx_key_hook(mlx, &key_hook, &fdf);
	// mlx_loop_hook(mlx, &draw_hook, &fdf); // under work
	mlx_loop(mlx);
	mlx_terminate(mlx);
	// printf("this %f \n", map.original[0].x);
	return (EXIT_SUCCESS);
}
