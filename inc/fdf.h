/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:17:01 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/28 17:17:25 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_h
# define FDF_h

# include "MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h> //printf
# include <math.h> // math
# include <fcntl.h> //open file
# include <unistd.h>

# define SCALE 100
# define WIDTH 3840
# define HEIGHT 2160
# define MALLOC "Memory allocation failed"
# define MAP "Invalid map"
# define FILE "Invalid file name"

typedef struct s_colors{
	uint32_t non_elevated;
	uint32_t elevated;
	uint32_t background;
}		t_colors;

typedef struct s_color{
	uint8_t r[2];
	uint8_t g[2];
	uint8_t b[2];
	uint8_t a[2];
	uint8_t a_ip;
	uint8_t r_ip;
	uint8_t g_ip;
	uint8_t b_ip;
}		t_color;

typedef struct s_linevars{
	int sx;
	int dx;
	int sy;
	int dy;
	float dz;
	int steps;
	int err;
	int e2;
	float t;
}		t_linevars;

typedef struct s_draw{
	int x1;
	int y1;
	int z1;
	int x2;
	int y2;
	int z2;
	uint32_t c1;
	uint32_t c2;
}		t_draw;

typedef struct s_point{
	float x;
	float y;
	float z;
	uint32_t color;
}		t_point;

typedef struct s_map{
	t_point		*original;
	t_point		*new2d;
	t_colors	cl;
	int			size;
	int			width;
	int			height;
	int			max_height;
	float		alpha_x;
	float		alpha_z;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	float		x_offset;
	float		y_offset;
	float		zoom;
	float		z_scale;
}		t_map;

typedef struct s_fdf{
	t_map		*map;
	mlx_image_t	*img;
	mlx_t		*mlx;
}		t_fdf;

typedef float (*PointAccessor)(t_point *point);

//initiate
void	set_elevation(t_map *map);
void	define_colors(t_colors *cl);
void	initiate_values_map(t_map *map);
void	set_z_scale(t_map *map);

//operators
void	rotation_X(t_map *map, float theta);
void	rotation_Y(t_map *map, float theta);
void	rotation_Z(t_map *map, float theta);
void	special_view(t_map *map, float alpha_x, float alpha_z);
void	isometric_view(t_map *map);
void	dimetric_view(t_map *map);
void	apply_scale_z(t_map *map);
void	zoom(t_map *map);
void	translate(t_map *map);

//drawing
void	draw_line(int32_t *pixels, int width, t_draw start_end);
void	draw_current_state(int32_t *pixels, mlx_image_t* img, t_map *map);
void	reset_background(t_fdf *fdf);
void	do_operations(t_map *map);

//Colors
uint32_t	interpolate_color(uint32_t c1, uint32_t c2, float t);
void		set_colors(t_map *map);

int		find_highest(t_point *points, int size, PointAccessor accessor);
int		find_lowest(t_point *points, int size, PointAccessor accessor);
float	get_x(t_point *point);
float	get_y(t_point *point);
float	get_z(t_point *point);

//map parsing
float	calc_interval(t_map *map);
int32_t	ft_atoi_base(char *str, int base);
int		get_height(t_map *map, int *fd);
int		get_width(t_map *map, int *fd);
t_map	*map_parsing(char *av);

//operations
void	copy_map(t_map *map);

//hooks
void	ft_scrollhook(double xdelta, double ydelta, void *param);
void	ft_hook_rotate(void *param);
void	ft_hook(void *param);
void	draw_hook(void *param);

//error
void	close_fds(int *fd, int amount);
void	exit_error(t_map *map, int *fd, int error, const char *msg);

#endif
