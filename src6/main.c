/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/25 17:05:45 by vlopatin         ###   ########.fr       */
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

t_fdf	initialize_fdf()
{
	t_fdf	fdf;
	// t_map	map;

	// fdf.map = map_parsing();
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!fdf.mlx)
		ft_error(); // handle this better
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	if (!fdf.img || (mlx_image_to_window(fdf.mlx, fdf.img, 0, 0) < 0))
		ft_error(); // handle this better
	return (fdf);
}

int32_t	main(int ac, char **av)
{
	t_fdf fdf;

	fdf = initialize_fdf();
	t_map map;

	fdf.map = &map;
	// fdf.img = img;
	// fdf.mlx = mlx;
	initiate_values_map(&map);
	if (ac == 2)
		map_parsing(&map, av[1]);
	copy_map(&map);
	// set_z_scale(&map); //implement this next, set z scale depending on what kind of elevation difference there is
	draw(&map);
	int32_t* pixels = (int32_t*)fdf.img->pixels;

	draw_current_state(pixels, fdf.img, &map);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_scroll_hook(fdf.mlx, &ft_scrollhook, &fdf);
	mlx_loop_hook(fdf.mlx, &ft_hook, &fdf);
	mlx_loop_hook(fdf.mlx, &ft_hook_rotate, &fdf);
	mlx_loop_hook(fdf.mlx, &draw_hook, &fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
