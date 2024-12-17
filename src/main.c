// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "fdf.h"
#define WIDTH 3000
#define HEIGHT 2000

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

void	create_coordinates(Map map)
{
	double x[] = {0, 1, 0, 1};
	double y[] = {0, 0, 1, 1};
}

Map populate_map()
{
	Map map;
	int i;
	int j;

	i = 0;
	map.width = 3;
	map.height = 4;
	while (i < map.width)
	{
		j = 0;
		while (j < map.height)
		{
			map.z[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
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

	// Even after the image is being displayed, we can still modify the buffer.
	// draw_line(pixels, img->width, 100, 100, 600, 500, 0xFF0000FF);
	// draw_line(pixels, img->width, 500, 500, 900, 100, 0xFF0000FF);
	int32_t* pixels = (int32_t*)img->pixels;
	Map map;
	map = populate_map();
	double x[] = {0, 1, 0, 1};
	double y[] = {0, 0, 1, 1};
	double z[] = {0, 0, 0, 0};
	
	create_coordinates(map);
	scale(map);

	draw_line(pixels, img->width, x[0], y[0], x[1], y[1], 0xFF00FF00);
	draw_line(pixels, img->width, x[0], y[0], x[2], y[2], 0xFF00FF00);
	draw_line(pixels, img->width, x[1], y[1], x[3], y[3], 0xFF00FF00);
	draw_line(pixels, img->width, x[2], y[2], x[3], y[3], 0xFF00FF00);

	rotation_X(y, z);
	rotation_Y(x, z);
	// rotation_Z(x, y);

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
	// grid(img, 150, 150, 250, 250);


	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

