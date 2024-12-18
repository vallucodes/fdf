/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:17:01 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/18 16:03:03 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_h
# define FDF_h

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h> // math

# define SCALE 10

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
	int x;
	int y;
	int z;
}		Point;

typedef struct {
	Point *points;
	int size;
	int width;
	int height;
	int max_height;
}		Map;

void	draw_line(int32_t* pixels, int width, int x1, int y1, int x2, int y2, int color);
void	grid(mlx_image_t* img, int x1, int x2, int y1, int y2);

void	rotation_X(Map *map);
void	rotation_Y(Map *map);
void	rotation_Z(Map *map);
void	scale(Map *map);

void	draw(int32_t *pixels, mlx_image_t* img, Point *point1, Point *point2);
void	draw_current_state(int32_t *pixels, mlx_image_t* img, Map *map);

#endif
