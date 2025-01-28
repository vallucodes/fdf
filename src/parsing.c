/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:25:13 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/28 16:26:40 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#include <stdio.h>

static void	parse_row(t_map *map, char *arr, int *c)
{
	int	j;
	float	interval;

	j = 0;
	interval = calc_interval(map);
	while(arr[j] && arr[j] != '\n')
	{
		map->original[*c].z = ft_atoi_base(&arr[j], 10) * interval / 2;
		map->original[*c].x = ((*c) % map->width) * interval - map->width / 2 * interval;
		map->original[*c].y = ((*c) / map->width) * interval - map->height / 2 * interval;
		while(ft_isspace(arr[j]))
			j++;
		while(arr[j] == '-' || ft_isdigit(arr[j]))
			j++;
		if(arr[j] == ',' && arr[j + 1] == '0')
		{
			j += 3;
			map->original[*c].color = ft_atoi_base(&arr[j], 16);
		}
		else
			map->original[*c].color = 0;
		while(ft_isalnum(arr[j]))
			j++;
		while(ft_isspace(arr[j]))
			j++;
		(*c)++;
	}
}

static void	populate_map(t_map *map, int *fd)
{
	int		i;
	int		c;
	char	*arr;
	int		error;

	map->size = map->width * map->height;
	map->original = malloc(map->size * sizeof(t_point));
	map->new2d = malloc(map->size * sizeof(t_point));
	if(!map->original || !map->new2d)
		exit_error(map, fd, 1, MALLOC);
	c = 0;
	i = 0;
	error = 0;
	while (i < map->height)
	{
		arr = get_next_line(fd[2], &error);
		if (error == 1)
			exit_error(map, fd, 1, MALLOC);
		parse_row(map, arr, &c);
		free(arr);
		arr = NULL;
		i++;
	}
}

static void	load_data(t_map *map, int *fd)
{
	map->width = get_width(map, fd);
	map->height = get_height(map, fd);
	populate_map(map, fd);
}

static int	open_file(char *map_name, int *fd)
{
	fd[0] = open(map_name, O_RDONLY);
	fd[1] = open(map_name, O_RDONLY);
	fd[2] = open(map_name, O_RDONLY);
	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1)
		return (0);
	return (1);
}

t_map	*map_parsing(char *av)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_error(NULL, NULL, 0, MALLOC);
	int fd[3] = {-1, -1, -1};
	if (!open_file(av, fd))
		exit_error(map, fd, 2, FILE);
	load_data(map, fd);
	close_fds(fd, 3);
	return (map);
}
