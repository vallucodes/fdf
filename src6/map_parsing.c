/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:25:13 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/26 10:51:05 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// error handling not checked properly. Need to modify GNL to know if NULL is due to malloc fail or not

#include "../include/fdf.h"
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

int	calc_interval(t_map *map)
{
	int	interval;

	interval = ft_min(WIDTH / map->width, HEIGHT / map->height) / 2;
	interval = ft_max(2, interval);
	return(interval);
}

static void	parse_row(t_map *map, char *arr, int *c)
{
	int	j;
	int	interval;

	j = 0;
	interval = calc_interval(map);
	while(arr[j] && arr[j] != '\n')
	{
		map->original[*c].z = ft_atoi_base(&arr[j], 10) * interval;
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

static void	populate_map(t_map *map, int fd)
{
	int		i;
	int		c;
	char	*arr;

	map->size = map->width * map->height;
	map->original = malloc(map->size * sizeof(t_point));
	map->new2d = malloc(map->size * sizeof(t_point));
	if(!map->original || !map->new2d)
		exit_error(map, NULL, 1);
	c = 0;
	i = 0;
	while (i < map->height)
	{
		arr = get_next_line(fd);
		if (!arr)
			exit_error(map, NULL, 1);
		parse_row(map, arr, &c);
		free(arr);
		arr = NULL;
		i++;
	}
}

static int	load_data(t_map *map, int *fd)
{
	map->width = get_width(fd);
	map->height = get_height(fd[1]);
	populate_map(map, fd[2]); // error handling in these is done
	return (1); //do i need this return?
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

int	map_parsing(t_map *map, char *av)
{
	int fd[3] = {-1, -1, -1};

	if (!open_file(av, fd))
		exit_error(NULL, fd, 3);
	if (!load_data(map, fd))
	{
		close_fds(fd, 3);
		return (0);
	}
	close_fds(fd, 3);
	return (1);
}
