/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:17:01 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/19 17:55:02 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_h
# define FDF_h

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h> //printf
# include <math.h> // math

# define SCALE 50
# define WIDTH 2000
# define HEIGHT 1500

typedef struct {
	int sx;
	int dx;
	int sy;
	int dy;
	int err;
	int e2;
}		LineVars;

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
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
}		Point;

typedef struct {
	Point *points;
	int size;
	int width;
	int height;
	int max_height;
}		Map;



void	grid(mlx_image_t* img, int x1, int x2, int y1, int y2);

//initiate
void	populate_map(Map *map);
void	define_angles(Angle *an);

//operators
void	rotation_X(Map *map, double theta);
void	rotation_Y(Map *map, double theta);
void	rotation_Z(Map *map, double theta);
void	scale(Map *map);
void	translate(Map *map);

//drawing
void	draw(int32_t *pixels, mlx_image_t* img, Point *point1, Point *point2);
void	draw_line(int32_t *pixels, int width, Draw start_end, int color);
void	draw_current_state(int32_t *pixels, mlx_image_t* img, Map *map);

//small_operations
void	ft_round(Map *map);
void	print_result(Map *map);

#endif
