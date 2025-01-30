/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:17:01 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/29 14:33:41 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>	//abs, malloc, free, exit
# include <math.h>		// math
# include <fcntl.h>		//open
# include <unistd.h>	//close

# define WIDTH	3840
# define HEIGHT	2160
# define MALLOC	"Memory allocation failed"
# define MAP	"Invalid map"
# define FILE	"Invalid file name"

typedef struct s_colors{
	uint32_t	non_elevated;
	uint32_t	elevated;
	uint32_t	background;
}		t_colors;

typedef struct s_color{
	uint8_t	r[2];
	uint8_t	g[2];
	uint8_t	b[2];
	uint8_t	a[2];
	uint8_t	a_ip;
	uint8_t	r_ip;
	uint8_t	g_ip;
	uint8_t	b_ip;
}		t_color;

typedef struct s_linevars{
	int		sx;
	int		dx;
	int		sy;
	int		dy;
	float	dz;
	int		steps;
	int		err;
	int		e2;
	float	t;
}		t_linevars;

typedef struct s_draw{
	int			x1;
	int			y1;
	int			z1;
	int			x2;
	int			y2;
	int			z2;
	uint32_t	c1;
	uint32_t	c2;
}		t_draw;

typedef struct s_point{
	float		x;
	float		y;
	float		z;
	uint32_t	color;
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

//map parsing
float		calc_interval(t_map *map);
int			get_height(t_map *map, int *fd);
int			get_width(t_map *map, int *fd);
void		parse_row(t_map *map, char *arr, int *c);
t_map		*map_parsing(char *av);

//initiate
void		set_elevation(t_map *map);
void		define_colors(t_colors *cl);
void		initiate_values_map(t_map *map);
void		set_z_scale(t_map *map);

//colors
uint32_t	interpolate_color(uint32_t c1, uint32_t c2, float t);
void		set_colors(t_map *map);
int			find_highest(t_point *points, int size);
int			find_lowest(t_point *points, int size);

//movement operators
void		rotation_x(t_map *map, float theta);
void		rotation_y(t_map *map, float theta);
void		rotation_z(t_map *map, float theta);
void		special_view(t_map *map, float alpha_x, float alpha_z);
void		isometric_view(t_map *map);
void		dimetric_view(t_map *map);
void		apply_scale_z(t_map *map);
void		zoom(t_map *map);
void		translate(t_map *map);

//drawing
void		draw_line(int32_t *pixels, int width, t_draw start_end);
void		draw_current_state(int32_t *pixels, mlx_image_t *img, t_map *map);

//map operations
void		reset_background(t_fdf *fdf);
void		do_operations(t_map *map);

//hooks
void		ft_scrollhook(double xdelta, double ydelta, void *param);
void		ft_hook_rotate(void *param);
void		ft_hook(void *param);
void		ft_hook_scroll(void *param);
void		draw_hook(void *param);

//error
void		close_fds(int *fd, int amount);
void		exit_error(t_map *map, int *fd, int error, const char *msg);
void		check_errors(t_map *map, int *fd, char *arr, int error);

#endif
