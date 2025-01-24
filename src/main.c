/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/24 16:35:16 by vlopatin         ###   ########.fr       */
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

void	reset_background(int32_t* pixels, t_fdf *fdf)
{
	int i = 0;

	while (i < WIDTH * HEIGHT)
	{
		pixels[i] = fdf->map->cl.background;
		i++;
	}
}

void	draw(t_map *map)
{
	copy_map(map);
	scale_z(map);
	isometric_view(map);
	rotation_X(map, map->angle_x);
	rotation_Y(map, map->angle_y);
	rotation_Z(map, map->angle_z);
	scale(map);
	translate(map);
	set_colors(map);
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
	fdf.mlx = mlx;

	initiate_values_map(&map);
	if (ac == 2)
		map_parsing(&map, av[1]);
	copy_map(&map);
	// set_z_scale(&map); //implement this next, set z scale depending on what kind of elevation difference there is
	draw(&map);

	int32_t* pixels = (int32_t*)img->pixels;

	// display_new_map(&map);
	draw_current_state(pixels, img, &map);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_scroll_hook(mlx, &ft_scrollhook, &fdf);
	mlx_loop_hook(mlx, &ft_hook, &fdf);
	mlx_loop_hook(mlx, &ft_hook_rotate, &fdf);
	mlx_loop_hook(mlx, &draw_hook, &fdf);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
