/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/03 16:05:37 by vlopatin         ###   ########.fr       */
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


// align to center is under work.
void	align_to_center(Map *map)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	find_highest(map->points, map->size, get_x);
	find_lowest(map->points, map->size, get_x);
	find_highest(map->points, map->size, get_y);
	find_lowest(map->points, map->size, get_y);


}

int32_t	main(int ac, char **av)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	Map map;
	Angle an;
	Colors cl;

	if (ac == 2)
		map_parsing(&map, av[1]);
	set_elevation(&map);
	define_colors(&cl);
	set_colors(&map, &cl);
	// Create and display the image.
	int width = WIDTH;
	int height = HEIGHT;
	mlx_image_t* img = mlx_new_image(mlx, width, height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	int32_t* pixels = (int32_t*)img->pixels;

	define_angles(&an);
	// print_result(&map);
	scale(&map);

	rotation_X(&map, an.angle_x);
	rotation_Y(&map, an.angle_y);
	rotation_Z(&map, an.angle_z);

	align_to_center(&map); // under work
	translate(&map);

	print_result(&map);
	ft_round(&map);
	draw_current_state(pixels, img, &map);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
