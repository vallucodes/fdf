/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/22 15:40:24 by vlopatin         ###   ########.fr       */
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

// 	printf("actual point: %f\n", map->points[0].x);
// }

void	reset_background(int32_t* pixels, t_fdf *fdf)
{
	int i = 0;

	while (i < WIDTH*HEIGHT)
	{
		pixels[i] = fdf->cl.background;
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
			fdf->map->points[i].x += 50;
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

void	draw_hook(void *param) // under work, trying to implement rotations
{
	t_fdf *fdf = (t_fdf *)param;
	reset_background((int32_t*)fdf->img->pixels, fdf);
	draw_current_state((int32_t*)fdf->img->pixels, fdf->img, fdf->map);
}

// void	print_pixels(int32_t* pixels)
// {
// 	int i = 0;

// 	while (i < WIDTH*HEIGHT)
// 	{
// 		printf("%i\n", pixels[i]);
// 		i++;
// 	}
// }

// void	draw(t_map *map)
// {
// 	t_point *original;
// 	t_point *new3d;

// 	original = &map->points;

// 	rotation_X(&map, map.angle_x);
// 	rotation_Y(&map, map.angle_y);
// 	rotation_Z(&map, map.angle_z);
// }

void	initiate_values_map(t_map *map)
{
	map->angle_x = atan(sqrt(1.0 / 2.0));
	map->angle_y = atan(sqrt(1.0 / 2.0));
	map->angle_z = M_PI/5;
	map->x_offset = WIDTH / 2;
	map->y_offset = HEIGHT / 2;
	map->z_scale = 60;
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

	t_colors cl;
	fdf.map = &map;
	fdf.img = img;

	initiate_values_map(&map);
	if (ac == 2)
		map_parsing(&map, av[1]);
	// set_elevation(&map);
	define_colors(&cl);
	fdf.cl = cl;
	set_colors(&map, &cl);

	int32_t* pixels = (int32_t*)img->pixels;

	// print_result(&map);
	// scale(&map);

	rotation_X(&map, map.angle_x);
	rotation_Y(&map, map.angle_y);
	rotation_Z(&map, map.angle_z);

	// print_result(&map);
	// automatic_scale(&map);
	align_to_center(&map);
	// move(&map);
	// translate(&map);


	ft_round(&map);
	draw_current_state(pixels, img, &map);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, &ft_hook, NULL);

	mlx_key_hook(mlx, &key_hook, &fdf);
	mlx_loop_hook(mlx, &draw_hook, &fdf); // under work
	mlx_loop(mlx);
	mlx_terminate(mlx);
	// printf("this %f \n", map.points[0].x);
	return (EXIT_SUCCESS);
}
