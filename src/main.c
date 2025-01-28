/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/28 16:15:36 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../inc/fdf.h"

// to do
// check all header includes that they work
// arrange functions and files maybe better
// norminette

t_fdf	initialize_fdf(char *filename)
{
	t_fdf	fdf;

	fdf.map = map_parsing(filename);
	initiate_values_map(fdf.map);
	set_z_scale(fdf.map);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!fdf.mlx)
		exit_error(fdf.map, NULL, 0, mlx_strerror(mlx_errno));
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	if (!fdf.img || (mlx_image_to_window(fdf.mlx, fdf.img, 0, 0) < 0))
	{
		mlx_close_window(fdf.mlx);
		exit_error(fdf.map, NULL, 0, mlx_strerror(mlx_errno));
	}
	return (fdf);
}

int32_t	main(int ac, char **av)
{
	t_fdf fdf;

	if (ac != 2)
		return (1);
	fdf = initialize_fdf(av[1]);
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
