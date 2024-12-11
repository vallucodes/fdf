// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "fdf.h"
#define WIDTH 1000
#define HEIGHT 1000

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
	int width = 1000;
	int height = 1000;
	mlx_image_t* img = mlx_new_image(mlx, width, height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	int32_t* pixels = (int32_t*)img->pixels;
	// draw_line(pixels, img->width, 100, 100, 600, 500, 0xFF0000FF);
	// draw_line(pixels, img->width, 500, 500, 900, 100, 0xFF0000FF);
	draw_line(pixels, img->width, 500, 500, 600, 500, 0xFF0000FF); // 0 degrees (right)
	draw_line(pixels, img->width, 500, 500, 560, 560, 0xFF0000FF); // ~30 degrees
	draw_line(pixels, img->width, 500, 500, 530, 600, 0xFF0000FF); // ~60 degrees
	draw_line(pixels, img->width, 500, 500, 500, 600, 0xFF0000FF); // 90 degrees (down)
	draw_line(pixels, img->width, 500, 500, 470, 560, 0xFF0000FF); // ~120 degrees
	draw_line(pixels, img->width, 500, 500, 440, 530, 0xFF0000FF); // ~150 degrees
	draw_line(pixels, img->width, 500, 500, 400, 500, 0xFF0000FF); // 180 degrees (left)
	draw_line(pixels, img->width, 500, 500, 440, 470, 0xFF0000FF); // ~210 degrees
	draw_line(pixels, img->width, 500, 500, 470, 440, 0xFF0000FF); // ~240 degrees
	draw_line(pixels, img->width, 500, 500, 500, 400, 0xFF0000FF); // 270 degrees (up)
	draw_line(pixels, img->width, 500, 500, 530, 440, 0xFF0000FF); // ~300 degrees
	draw_line(pixels, img->width, 500, 500, 560, 470, 0xFF0000FF); // ~330 degrees


	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

