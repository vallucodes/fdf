// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "fdf.h"
#define WIDTH 1200
#define HEIGHT 1200

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

void	isometric_conversion(int *x, int *y)
{
	int i;
	int temp;

	temp = 0;
	i = 1;
	while (i < 4)
	{
		x[i] = x[i - 1] + 75;
		y[i] = y[i - 1] + 50;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		printf("x:%i, y:%i\n", x[i], y[i]);
		i++;
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
	int width = 1000;
	int height = 1000;
	mlx_image_t* img = mlx_new_image(mlx, width, height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	// draw_line(pixels, img->width, 100, 100, 600, 500, 0xFF0000FF);
	// draw_line(pixels, img->width, 500, 500, 900, 100, 0xFF0000FF);
	int x[] = {150, 250, 150, 250};
	int y[] = {150, 150, 250, 250};

	isometric_conversion(x, y);
	int32_t* pixels = (int32_t*)img->pixels;
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

