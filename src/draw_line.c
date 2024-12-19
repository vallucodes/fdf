/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:16:01 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/19 17:24:36 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	sx(int x1, int x2)
{
	if (x1 > x2)
		return (-1);
	else
		return (1);
}

static int	sy(int y1, int y2)
{
	if (y1 > y2)
		return (-1);
	else
		return (1);
}

void draw_line(int32_t *pixels, int width, Draw start_end, int color)
{
	LineVars	vars;
	int err;
	int e2;

	vars.dx = abs(start_end.x2 - start_end.x1);
	vars.dy = abs(start_end.y2 - start_end.y1);
	vars.sx = sx(start_end.x1, start_end.x2);
	vars.sy = sy(start_end.y1, start_end.y2);
	err = vars.dx - vars.dy;

	while (!(start_end.x1 > start_end.x2 && start_end.y1 > start_end.y2))
	{
		pixels[start_end.y1 * width + start_end.x1] = color;
		if (start_end.x1 == start_end.x2 && start_end.y1 == start_end.y2)
			break;
		e2 = 2 * err;
		if (e2 > -vars.dy)
		{
			err -= vars.dy;
			start_end.x1 += vars.sx;
		}
		if (e2 < vars.dx)
		{
			err += vars.dx;
			start_end.y1 += vars.sy;
		}
	}
}


