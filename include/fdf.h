/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:17:01 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/12 13:34:30 by vlopatin         ###   ########.fr       */
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

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h> // math

void	draw_line(int32_t* pixels, int width, int x1, int y1, int x2, int y2, int color);
void	grid(mlx_image_t* img, int x1, int x2, int y1, int y2);

#endif
