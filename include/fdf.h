/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:17:01 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/17 21:38:12 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_h
# define FDF_h

typedef struct {
	int sx;
	int dx;
	int sy;
	int dy;
	int err;
	int e2;
} LineVars;

typedef struct {
	int **z;
	int width;
	int height;
	int max_height;
} Map;

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h> // math

# define SCALE 100

void	draw_line(int32_t* pixels, int width, int x1, int y1, int x2, int y2, int color);
void	grid(mlx_image_t* img, int x1, int x2, int y1, int y2);

void	rotation_X(double *y, double *z);
void	rotation_Y(double *x, double *z);
void	rotation_Z(double *x, double *y);
void	scale(Map map);

#endif
