/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:23:59 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/22 10:56:55 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_little_endian()
{
	// Create a 2-byte integer with a known value
	unsigned short int num = 0x1;

	// Cast the address of num to a pointer to a byte (char *)
	unsigned char *byte_ptr = (unsigned char*)&num;

	// Check the first byte
	if (*byte_ptr == 0x1)
		return 1;
	return 0;
}

static void	color_to_rgba(uint32_t color, t_color *c, int i)
{
	c->a[i] = (color >> 24) & 0xFF;
	c->r[i] = (color >> 16) & 0xFF;
	c->g[i] = (color >> 8) & 0xFF;
	c->b[i] = color & 0xFF;
}

uint32_t	interpolate_color(uint32_t c1, uint32_t c2, float t)
{
	t_color c;

	color_to_rgba(c1, &c, 0);
	color_to_rgba(c2, &c, 1);

	c.a_ip = c.a[0] + (c.a[1] - c.a[0]) * t;
	c.b_ip = c.b[0] + (c.b[1] - c.b[0]) * t;
	c.g_ip = c.g[0] + (c.g[1] - c.g[0]) * t;
	c.r_ip = c.r[0] + (c.r[1] - c.r[0]) * t;

	if (is_little_endian() == 1)
	{
		return ((0xFF << 24) | (c.b_ip << 16) | (c.g_ip << 8) | c.r_ip);
	}
	else
		return ((c.r_ip << 24) | (c.g_ip << 16) | (c.b_ip << 8) | 0xFF);
}
