/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:23:59 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/20 14:04:28 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"

#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t r1;
	uint8_t g1;
	uint8_t b1;
	uint8_t a1;
	uint8_t r2;
	uint8_t g2;
	uint8_t b2;
	uint8_t a2;
	uint8_t a;
	uint8_t r;
	uint8_t g;
	uint8_t b;
}		Color;

static void	color_to_rgba(uint32_t color, Color *c)
{
	c->a1 = (color >> 24) & 0xFF;
	c->r1 = (color >> 16) & 0xFF;
	c->g1 = (color >> 8) & 0xFF;
	c->b1 = color & 0xFF;
}

uint32_t	interpolate_color(uint32_t color1, uint32_t color2, float t)
{
	Color c;

	color_to_rgba(color1, &c);
	color_to_rgba(color2, &c);

	c.a = c.a1 + (c.a2 - c.a1) * t;
	c.r = c.r1 + (c.r2 - c.r1) * t;
	c.g = c.g1 + (c.g2 - c.g1) * t;
	c.b = c.b1 + (c.b2 - c.b1) * t;

	return ((c.a << 24) | (c.r << 16) | (c.g << 8) | c.b);
}

int main() {
    uint32_t color1 = 0xFF00FF00;  // Green (start)
    uint32_t color2 = 0xFFFF0000;  // Red (end)
    int steps = 10;  // Number of gradient steps

    // Print the gradient
    for (int i = 0; i <= steps; i++) {
        float t = (float)i / steps;  // Fractional value from 0 to 1
        uint32_t color = interpolate_color(color1, color2, t);

        // Print the interpolated color (in hexadecimal)
        printf("Step %d: 0x%08X\n", i, color);
    }

    return 0;
}
