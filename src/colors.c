/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:23:59 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/23 14:14:04 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color_to_rgba(uint32_t color, Color *c, int i)
{
	c->a[i] = (color >> 24) & 0xFF;
	c->r[i] = (color >> 16) & 0xFF;
	c->g[i] = (color >> 8) & 0xFF;
	c->b[i] = color & 0xFF;
}

uint32_t	interpolate_color(Draw start_end, float t)
{
	Color	c;

	color_to_rgba(start_end.c1, &c, 0);
	color_to_rgba(start_end.c2, &c, 1);

	c.a_ip = c.a[0] + (c.a[1] - c.a[0]) * t;
	c.r_ip = c.r[0] + (c.r[1] - c.r[0]) * t;
	c.g_ip = c.g[0] + (c.g[1] - c.g[0]) * t;
	c.b_ip = c.b[0] + (c.b[1] - c.b[0]) * t;

	return ((c.a_ip << 24) | (c.r_ip << 16) | (c.g_ip << 8) | c.b_ip);
}
