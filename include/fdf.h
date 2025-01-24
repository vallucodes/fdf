/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:17:01 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/24 16:36:04 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_h
# define FDF_h

# include "MLX42/MLX42.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h> //printf
# include <math.h> // math
# include <fcntl.h> //open file
# include <unistd.h>

# define SCALE 100
# define WIDTH 2000
# define HEIGHT 1500

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

//operators
void	rotation_X(t_map *map, float theta);
void	rotation_Y(t_map *map, float theta);
void	rotation_Z(t_map *map, float theta);
void	isometric_rotation(t_map *map);
void	scale_z(t_map *map);
void	scale(t_map *map);
void	translate(t_map *map);

//drawing
void	draw_line(int32_t *pixels, int width, t_draw start_end);
void	draw_current_state(int32_t *pixels, mlx_image_t* img, t_map *map);
void	reset_background(int32_t* pixels, t_fdf *fdf);
void	draw(t_map *map);

//Colors
uint32_t	interpolate_color(uint32_t c1, uint32_t c2, float t);
void		set_colors(t_map *map);

int		find_highest(t_point *points, int size, PointAccessor accessor);
int		find_lowest(t_point *points, int size, PointAccessor accessor);

//map parsing
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		is_num(char c);
int		is_alnum(char c);
int		is_space(char c);
int32_t	ft_atoi_base(char *str, int base);
void	clear_fd(int fd);
int		get_height(int fd);
int		get_width(int fd);
int		map_parsing(t_map *map, char *av);

//operations
void display_old_map(t_map *map);
void display_new_map(t_map *map);
void	print_result(t_map *map);
void	copy_map(t_map *map);

//hooks
void	ft_scrollhook(double xdelta, double ydelta, void *param);
void	ft_hook_rotate(void *param);
void	ft_hook(void *param);
void	draw_hook(void *param);

void	isometric_view(t_map *map);

#endif
