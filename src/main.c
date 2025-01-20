/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/20 15:57:15 by vlopatin         ###   ########.fr       */
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

void	reset_background(int32_t* pixels)
{
	int i = 0;

	while (i < WIDTH*HEIGHT)
	{
		pixels[i] = 0;
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
		// mlx_delete_image(fdf->mlx, fdf->img);
		// mlx_image_t* img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
		// if (!img || (mlx_image_to_window(fdf->mlx, img, 0, 0) < 0))
		// 	ft_error();
		// fdf->img = img;
		reset_background((int32_t*)fdf->img->pixels);
		draw_current_state((int32_t*)fdf->img->pixels, fdf->img, fdf->map);
	}
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

int32_t	main(int ac, char **av)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	t_fdf fdf;
	t_map map;
	fdf.map = &map;
	t_angle an;
	t_colors cl;

	if (ac == 2)
		map_parsing(&map, av[1]);
	// set_elevation(&map);

	define_colors(&cl);
	set_colors(&map, &cl);
	// Create and display the image.
	int width = WIDTH;
	int height = HEIGHT;
	mlx_image_t* img = mlx_new_image(mlx, width, height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	fdf.img = img;
	int32_t* pixels = (int32_t*)img->pixels;

	define_angles(&an);
	// print_result(&map);
	scale(&map);

	rotation_X(&map, an.angle_x);
	rotation_Y(&map, an.angle_y);
	rotation_Z(&map, an.angle_z);

	// print_result(&map);
	automatic_scale(&map);
	align_to_center(&map);
	// move(&map);
	// translate(&map);


	ft_round(&map);
	draw_current_state(pixels, img, &map);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, &ft_hook, NULL);

	mlx_key_hook(mlx, &key_hook, &fdf);
	// mlx_loop_hook(mlx, &hook, &param);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	// printf("this %f \n", map.points[0].x);
	return (EXIT_SUCCESS);
}
