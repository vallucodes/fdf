/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:25:13 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/30 13:45:21 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/fdf.h"
# include <stdlib.h>
# include <stdio.h> //printf
# include <math.h> // math
# include <fcntl.h> //open file
# include <unistd.h>
# include <stdint.h>
# include "get_next_line.h"

typedef struct {
	float x;
	float y;
	float z;
	int elevated;
	uint32_t color;
}		Point;

typedef struct {
	Point *points;
	int size;
	int width;
	int height;
	int max_height;
}		Map;

int	get_height(int fd)
{
	char	*arr;
	int		height;

	height = 0;
	arr = get_next_line(fd);
	while (arr)
	{
		free(arr);
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
		if (arr[i] > 32 && arr[i] < 127)
		{
			while(arr[i] > 32 && arr[i] < 127)
				i++;
			width++;
		}
	}
	free(arr);
	return (width);
}

static int	is_valid(char c, int base)
{
	char digits[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char digits2[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while (base > 0)
	{
		base--;
		if(digits[base] == c || digits2[base] == c)
			return (1);
	}
	return (0);
}

static int	calc_nb(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (10 + c - 'a');
	else if (c >= 'A' && c <= 'Z')
		return (10 + c - 'A');
	return (0);
}

int32_t	ft_atoi_base(char *str, int base)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	i = 0;
	while(str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	res = 0;
	while(is_valid(str[i], base))
	{
		res = res * base + calc_nb(str[i]);
		i++;
	}
	return (res * sign);
}

int	populate_map2(Map *map, int fd)
{
	printf("populate map\n");
	// char	*arr;
	int		i;
	int		j;
	int		c;
	map->points = malloc(map->width * map->height * sizeof(Point));
	if(!map->points)
		return (0);
	c = 0;
	i = 0;
	while (i < map->height)
	{
		char *arr = get_next_line(fd);
		printf("round %i, arr %s", i, arr);
		j = 0;
		while(arr[j] && arr[j] != '\n')
		{
			map->points[c].z = ft_atoi_base(&arr[j], 10);
			map->points[c].x = c; //- i * map->width
			map->points[c].y = i;
			while(arr[j] == ' ')
				j++;
			while(arr[j] == '-' || (arr[j] >= '0' && arr[j] <= '9'))
				j++;
			if(arr[j] == ',' && arr[j + 1] == '0')
			{
				j += 3;
				map->points[c].color = ft_atoi_base(&arr[j], 16);
			}
			while(arr[j] && arr[j] != ' ' && arr[j] != '\n')
				j++;
			c++;
		}
		i++;
		free(arr);
	}
	return (1);
}

void	load_data(Map *map, int *fd)
{
	map->height = get_height(fd[0]);
	map->width = get_width(fd[1]);
	populate_map2(map, fd[2]);
	printf("fd: %i, %i, %i\n", fd[0], fd[1], fd[2]);
}

int	*open_file(char *map_name, int *fd)
{
	fd[0] = open(map_name, O_RDONLY);
	fd[1] = open(map_name, O_RDONLY);
	fd[2] = open(map_name, O_RDONLY);
	return (fd);
}

int	map_parsing(Map *map, char *av)
{
	printf("parsing\n");
	int fd[3];

	open_file(av, fd);
	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1)
		return -1;
	load_data(map, fd);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (0);
}

int main()
{
	Map map;
	map_parsing(&map, "10-2.fdf");
	int c = 0;
	while (c < map.height * map.width)
	{
		printf("xyz color:%i: %f, %f, %f, %i \n", c,  map.points[c].x, map.points[c].y, map.points[c].z, map.points[c].color);
		c++;
	}
}
