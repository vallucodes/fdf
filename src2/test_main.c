# include <stdlib.h>
# include <stdio.h> //printf
# include <math.h> // math
# include <fcntl.h> //open file
# include <unistd.h>
# include <stdint.h>

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

// int	get_height(int fd)
// {
// 	char	*arr;
// 	int		height;

// 	height = 0;
// 	while (arr)
// 	{
// 		arr = get_next_line(fd);
// 		height += 1;
// 	}
// 	free(arr);
// 	return (height);
// }

// int	get_width(int fd)
// {
// 	char	*arr;
// 	int		i;
// 	int		width;

// 	arr = get_next_line(fd);
// 	i = 0;
// 	width = 0;
// 	while(arr[i] && arr[i] != '\n')
// 	{
// 		while(arr[i] == ' ')
// 			i++;
// 		while(arr[i] > 32 && arr[i] < 127)
// 			i++;
// 		width++;
// 	}
// 	free(arr);
// 	return (width);
// }

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

void	populate_map2(Map *map, int fd)
{
	// char	*arr;
	int		i;
	int		j;
	int		c;
	fd += 1;
	map->width = 27;
	map->height = 1;
	map->points = malloc(map->width * map->height * sizeof(Point));

	c = 0;
	i = 0;
	while (i < map->height)
	{
		char arr[] = "0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 8,0xFFFFFF 8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0";
		// arr = get_next_line(fd);
		j = 0;
		while(arr[j] && arr[j] != '\n')
		{
			map->points[c].z = ft_atoi_base(&arr[j], 10);
			map->points[c].x = c;
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
		// free(arr);
	}
}

int main()
{
	Map map;
	int fd = 2;
	populate_map2(&map, fd);
	int c = 0;
	while (c < map.height * map.width)
	{
		printf("xyz color: %f, %f, %f, %i \n", map.points[c].x, map.points[c].y, map.points[c].z, map.points[c].color);
		c++;
	}
}
