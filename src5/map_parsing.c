/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:25:13 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/23 12:38:44 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// error handling not checked properly. Need to modify GNL to know if NULL is due to malloc fail or not

#include "fdf.h"
#include <string.h>

#include <stdio.h>

void display_parsed_map(t_map *map)
{
    int i;
    t_point *point;

    printf("Parsed Map (3D Grid):\n");
    printf("Rows: %d, Columns: %d\n", map->width, map->height);
    // printf("Height Range: Low = %.2d, High = %.2d\n", map->low, map->high);
    printf("=========================================\n");

    for (i = 0; i < map->size; i++)
    {
		point = &(map->original[i]);
		printf("Point[%d]: x=%.2f, y=%.2f, z=%.2f, color=0x%x\n",
				i, point->x, point->y, point->z, point->color);
        printf("\n");
    }
	// printf("angles 1: %f, 2: %f, 3: %f\n", map->xrotate, map->yrotate, map->zrotate);
    printf("=========================================\n");
}

static void	parse_row(t_map *map, char *arr, int *c)
{
	int	j;
	int	x_interval;
	int	y_interval;
	int	interval;

	j = 0;
	y_interval = 60;
	x_interval = 60;
	interval = 60;
	while(arr[j] && arr[j] != '\n')
	{
		map->original[*c].z = ft_atoi_base(&arr[j], 10) * interval;
		map->original[*c].x = ((*c) % map->width) * interval - map->width / 2 * interval;
		map->original[*c].y = ((*c) / map->width) * interval - map->height / 2 * interval;
		while(is_space(arr[j]))
			j++;
		while(arr[j] == '-' || is_num(arr[j]))
			j++;
		if(arr[j] == ',' && arr[j + 1] == '0')
		{
			j += 3;
			map->original[*c].color = ft_atoi_base(&arr[j], 16);
		}
		else
			map->original[*c].color = 0;
		while(is_alnum(arr[j]))
			j++;
		while(is_space(arr[j]))
			j++;
		(*c)++;
	}
}

static int	populate_map(t_map *map, int fd)
{
	int		i;
	int		c;
	char	*arr;

	map->size = map->width * map->height;
	map->original = malloc(map->size * sizeof(t_point));
	map->new2d = malloc(map->size * sizeof(t_point));
	// memset(map->original, 0, sizeof(t_point));
	if(!map->original || !map->new2d)
		return (0);
	c = 0;
	i = 0;
	while (i < map->height)
	{
		arr = get_next_line(fd);
		if (!arr)
			return (0);
		parse_row(map, arr, &c);
		free(arr);
		arr = NULL;
		i++;
	}
	display_parsed_map(map);
	return (1);
}

static int	load_data(t_map *map, int *fd)
{
	map->height = get_height(fd[0]);
	map->width = get_width(fd[1]);
	if (!populate_map(map, fd[2]))
		return (0);
	return (1);
}

static int	*open_file(char *map_name, int *fd)
{
	fd[0] = open(map_name, O_RDONLY);
	fd[1] = open(map_name, O_RDONLY);
	fd[2] = open(map_name, O_RDONLY);
	return (fd);
}

int	map_parsing(t_map *map, char *av)
{
	int fd[3];

	open_file(av, fd);
	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1)
	{
		if (fd[0] == -1)
			close(fd[0]);
		if (fd[1] == -1)
			close(fd[1]);
		if (fd[2] == -1)
			close(fd[2]);
		return (0);
	}
	if (!load_data(map, fd))
	{
		close(fd[0]);
		close(fd[1]);
		close(fd[2]);
		return (0);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (1);
}
