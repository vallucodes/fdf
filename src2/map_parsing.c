/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:25:13 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/28 16:43:40 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(int fd)
{
	char	*arr;
	int		height;

	height = 0;
	while (arr)
	{
		arr = get_next_line(fd);
		height += 1;
	}
	free(arr);
	return (height);
}

int	get_width(int fd)
{
	char	*arr;
	int		i;
	int		width;

	arr = get_next_line(fd);
	i = 0;
	width = 0;
	while(arr[i] && arr[i] != '\n')
	{
		while(arr[i] == ' ')
			i++;
		while(arr[i] > 32 && arr[i] < 127)
			i++;
		width++;
	}
	free(arr);
	return (width);
}

void	populate_map2(Map *map, int fd)
{
	char	*arr;
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 0;
	while (i < map->height)
	{
		arr = get_next_line(fd);
		j = 0;
		while(arr[j] && arr[j] != '\n')
		{
			while(arr[j] == ' ')
				j++;
			while(arr[j] > 32 && arr[j] < 127)
			{
				if(arr[j] == '-' || (arr[j] >= '0' && arr[j] <= '9'))
					map->points[c].z = ft_atoi(&arr[j]);
				while(arr[j] == '-' || (arr[j] >= '0' && arr[j] <= '9'))
					j++;
				if(arr[j] == ',' && arr[j + 1] == '0')
				{
					j++;
					map->points[c].color = ft_atohex(&arr[j]);
				}
				while(arr[j] || arr[j] != ' ' || arr[j] == '\n')
					j++;
				c++;
			}
		}
		i++;
		free(arr);
	}
}

void	load_data(Map *map, int fd)
{
	map->height = get_heigth(fd);
	map->width = get_width(fd);
	populate_map2(&map, fd);
}

int	open_directory(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}
	return (fd);
}

int	map_parsing(Map map, char *av)
{
	int fd;

	fd = open_file(av);
	if (fd == -1)
		return -1;
	load_data(&map, fd);

	close(fd);
}
