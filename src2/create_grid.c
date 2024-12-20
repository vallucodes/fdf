/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:31 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/20 13:42:10 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grid(mlx_image_t* img, int x1, int x2, int y1, int y2)
{
	int32_t* pixels = (int32_t*)img->pixels;
	while (y1 < y2)
	{
		while (x1 < x2)
		{
			draw_line(pixels, img->width, x1, y1, x1 + 100, y1, 0xFF0000FF);
			draw_line(pixels, img->width, x1, y1, x1, y1 + 100, 0xFF0000FF);
			x1 += 100;
		}
		draw_line(pixels, img->width, x1, y1, x1, y1 + 100, 0xFF0000FF);
		x1 = 150;
		y1 += 100;
	}
	draw_line(pixels, img->width, x1, y1, x2 + 50, y1, 0xFF0000FF);
}

typedef struct {
	uint8_t r1;
	uint8_t g1;
	uint8_t b1;
	uint8_t a1;
	uint8_t r2;
	uint8_t g2;
	uint8_t b2;
	uint8_t a2;
}		Color;
