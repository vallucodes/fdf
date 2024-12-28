/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:23:59 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/28 13:28:59 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static uint32_t	swap_eandinness(uint32_t color)
// {
// 	return ((color >> 24) & 0xFF) |
// 		((color >> 8) & 0xFF00) |
// 		((color << 8) & 0xFF0000) |
// 		((color << 24) & 0xFF000000);
// }

static void color_to_rgba(uint32_t color, Color *c, int i)
{
    c->a[i] = (color >> 24) & 0xFF;
    c->r[i] = (color >> 16) & 0xFF;
    c->g[i] = (color >> 8) & 0xFF;
    c->b[i] = color & 0xFF;
}

uint32_t interpolate_color(Draw start_end, float t)
{
	Color c;

	// Convert both colors to RGBA format
	color_to_rgba(start_end.c1, &c, 0);
	color_to_rgba(start_end.c2, &c, 1);

	// Interpolate each channel
	c.a_ip = c.a[0] + (c.a[1] - c.a[0]) * t;
	c.b_ip = c.b[0] + (c.b[1] - c.b[0]) * t;
	c.g_ip = c.g[0] + (c.g[1] - c.g[0]) * t;
	c.r_ip = c.r[0] + (c.r[1] - c.r[0]) * t;

	// Return the final interpolated color
	printf("color: 0x%8X\n", (0xFF << 24) | (c.r_ip << 16) | (c.g_ip << 8) | c.b_ip);
	return ((0xFF << 24) | (c.b_ip << 16) | (c.g_ip << 8) | c.r_ip);
	// return ((0xFF << 24) | (c.r_ip << 16) | (c.g_ip << 8) | c.b_ip);
}

int main()
{
    Draw start_end;

    // Example colors in 0xAARRGGBB format (e.g., ARGB)
    start_end.c1 = 0xFF;  // Blue
    start_end.c2 = 0xFF00;  // Green

    // Test interpolation with t=0.5 (halfway between c1 and c2)
    float t = 0.5;
    uint32_t interpolated_color = interpolate_color(start_end, t);

    // Extract RGBA components for the interpolated color
    Color c;
    color_to_rgba(interpolated_color, &c, 0);

    // Print the RGBA values of the interpolated color
    printf("Interpolated Color (RGBA):\n");
    printf("R: %d, G: %d, B: %d, A: %d\n", c.r[0], c.g[0], c.b[0], c.a[0]);
    printf("R: 0x%8X\n", interpolated_color);

    return 0;
}
