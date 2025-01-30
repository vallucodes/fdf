/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:25:20 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/29 14:55:14 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_fdf	initialize_fdf(char *map_name)
{
	t_fdf	fdf;

	fdf.map = map_parsing(map_name);
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
	t_fdf	fdf;

	if (ac != 2)
		exit_error(NULL, NULL, 4, FILE);
	fdf = initialize_fdf(av[1]);
	mlx_scroll_hook(fdf.mlx, &ft_scrollhook, &fdf);
	mlx_loop_hook(fdf.mlx, &ft_hook_scroll, &fdf);
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
