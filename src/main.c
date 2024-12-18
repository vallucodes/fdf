/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/18 15:58:45 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/fdf.h"
#define WIDTH 2000
#define HEIGHT 1500

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

void	print_result(Map *map)
{
	int i = 0;
	while (i < map->size)
	{
		printf("i: %i, ", i);
		printf("xyz: %i ", map->points[i].x);
		printf("%i ", map->points[i].y);
		printf("%i\n", map->points[i].z);
		i++;
	}
	printf("----------------------------------------------\n");
}
// c + map->width

void	translate(Map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->points[i].x += WIDTH / 4;
		map->points[i].y += HEIGHT / 8;
		i++;
	}
}

void	populate_map(Map *map)
{
	int x;
	int y;
	int i;

	x = -1;
	y = 0;
	i = 0;
	map->width = 30;
	map->height = 14;
	map->size = map->width * map->height;
	map->points = malloc(map->size * sizeof(Point));
	while (y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->points[i].x = x;
			map->points[i].y = y;
			map->points[i++].z = 0; //make function to get height later
		}
		y++;
	}
}

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
	populate_map(&map);
	scale(&map);

	rotation_X(&map);
	rotation_Y(&map);
	rotation_Z(&map);
	translate(&map);
	print_result(&map);
	draw_current_state(pixels, img, &map);
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

