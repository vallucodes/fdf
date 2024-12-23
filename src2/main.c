/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/23 13:15:25 by vlopatin         ###   ########.fr       */
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
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	int width = WIDTH;
	int height = HEIGHT;
	mlx_image_t* img = mlx_new_image(mlx, width, height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	int32_t* pixels = (int32_t*)img->pixels;
	Map map;
	Angle an;
	// Colors cl;
	define_angles(&an);
	// define_colors(&cl);
	populate_map(&map);
	print_result(&map);
	scale(&map);

	rotation_X(&map, an.angle_x);
	rotation_Y(&map, an.angle_y);
	rotation_Z(&map, an.angle_z);

	translate(&map);
	print_result(&map);
	ft_round(&map);
	draw_current_state(pixels, img, &map, &cl);
	/*
	int i = 0;
	while (i < 4)
	{
		printf("x:%.2f, y:%.2f, z:%.2f\n", x[i], y[i], z[i]);
		i++;
	}
	draw_line(pixels, img->width, x[0], y[0], x[1], y[1], 0xFF0000FF);
	draw_line(pixels, img->width, x[0], y[0], x[2], y[2], 0xFF0000FF);
	draw_line(pixels, img->width, x[1], y[1], x[3], y[3], 0xFF0000FF);
	draw_line(pixels, img->width, x[2], y[2], x[3], y[3], 0xFF0000FF);
	*/
	// grid(img, 150, 150, 250, 250);


	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

