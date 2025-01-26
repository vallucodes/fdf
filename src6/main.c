/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/26 12:42:04 by vlopatin         ###   ########.fr       */
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

t_fdf	initialize_fdf(char *filename)
{
	t_fdf	fdf;

	fdf.map = (t_map*)malloc(sizeof(t_map));
    if (!fdf.map)
    {
        printf("Failed to allocate memory for map");
        ft_error(); // handle this better
    }
	initiate_values_map(fdf.map);
	map_parsing(fdf.map, filename);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!fdf.mlx)
	{
		printf("!fdf.mlx");
		ft_error(); // handle this better
	}
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	if (!fdf.img || (mlx_image_to_window(fdf.mlx, fdf.img, 0, 0) < 0))
	{
		printf("fdf.img || <0");
		ft_error(); // handle this better
	}
	ft_putstr_fd("Init completed\n", 4);
	return (fdf);
}

int32_t	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	t_fdf fdf;
	// t_map map;
	// fdf.map = &map;

	// map_parsing(&map, av[1]);
	fdf = initialize_fdf(av[1]);
	// set_z_scale(&map); //implement this next, set z scale depending on what kind of elevation difference there is

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	write(1, "ok1\n", 4);
	mlx_scroll_hook(fdf.mlx, &ft_scrollhook, &fdf);
	mlx_loop_hook(fdf.mlx, &ft_hook, &fdf);
	mlx_loop_hook(fdf.mlx, &ft_hook_rotate, &fdf);
	mlx_loop_hook(fdf.mlx, &draw_hook, &fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	free(fdf.map->original);
	free(fdf.map->new2d);
	free(fdf.map);
	return (EXIT_SUCCESS);
}
