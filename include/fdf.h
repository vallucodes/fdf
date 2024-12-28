/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:17:01 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/28 16:06:01 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_h
# define FDF_h

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h> //printf
# include <math.h> // math
# include <fcntl.h> //open file
#include <unistd.h>

# define SCALE 40
# define WIDTH 2000
# define HEIGHT 1500

typedef struct {
	uint32_t non_elevated;
	uint32_t elevated;
}		Colors;

typedef struct {
	uint8_t r[2];
	uint8_t g[2];
	uint8_t b[2];
	uint8_t a[2];
	uint8_t a_ip;
	uint8_t r_ip;
	uint8_t g_ip;
	uint8_t b_ip;
}		Color;

typedef struct {
	int sx;
	int dx;
	int sy;
	int dy;
	float dz;
	int steps;
	int err;
	int e2;
	float t;
}		LineVars;

typedef struct {
	int x1;
	int y1;
	int z1;
	int x2;
	int y2;
	int z2;
	uint32_t c1;
	uint32_t c2;
}		Draw;

typedef struct {
	float angle_x;
	float angle_y;
	float angle_z;
}		Angle;

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

//initiate
void	populate_map(Map *map);
void	define_angles(Angle *an);
void	define_colors(Colors *cl);

//operators
void	rotation_X(Map *map, double theta);
void	rotation_Y(Map *map, double theta);
void	rotation_Z(Map *map, double theta);
void	scale(Map *map);
void	translate(Map *map);

//drawing
void	draw_line(int32_t *pixels, int width, Draw start_end);
void	draw_current_state(int32_t *pixels, mlx_image_t* img, Map *map, Colors *cl);

//Colors
uint32_t	interpolate_color(Draw cl, float t);

//small_operations
void	ft_round(Map *map);
void	print_result(Map *map);

#endif
