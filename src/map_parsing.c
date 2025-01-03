/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:25:13 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/03 14:48:24 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// error handling not checked properly. Need to modify GNL to know if NULL is due to malloc fail or not

# include "fdf.h"

static void	parse_row(Map *map, char *arr, int *c, int *i)
{
	int	j;

	j = 0;
	while(arr[j] && arr[j] != '\n')
	{
		map->points[*c].z = ft_atoi_base(&arr[j], 10);
		map->points[*c].x = *c - *i * map->width;
		map->points[*c].y = *i;
		while(is_space(arr[j]))
			j++;
		while(arr[j] == '-' || is_num(arr[j]))
			j++;
		if(arr[j] == ',' && arr[j + 1] == '0')
		{
			j += 3;
			map->points[*c].color = ft_atoi_base(&arr[j], 16);
		}
		else
			map->points[*c].color = 0;
		while(is_alnum(arr[j]))
			j++;
		while(is_space(arr[j]))
			j++;
		(*c)++;
	}
}

static int	populate_map(Map *map, int fd)
{
	int		i;
	int		c;
	char	*arr;

	map->size = map->width * map->height;
	map->points = malloc(map->size * sizeof(Point));
	if(!map->points)
		return (0);
	c = 0;
	i = 0;
	while (i < map->height)
	{
		arr = get_next_line(fd);
		if (!arr)
			return (0);
		parse_row(map, arr, &c, &i);
		free(arr);
		arr = NULL;
		i++;
	}
	return (1);
}

static int	load_data(Map *map, int *fd)
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

int	map_parsing(Map *map, char *av)
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
