/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:16:01 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/20 13:01:17 by vlopatin         ###   ########.fr       */
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
static void	initiate_vars(LineVars *vars, Draw start_end)
{
	vars->dx = abs(start_end.x2 - start_end.x1);
	vars->dy = abs(start_end.y2 - start_end.y1);
	vars->sx = sx(start_end.x1, start_end.x2);
	vars->sy = sy(start_end.y1, start_end.y2);
	vars->dz = (start_end.z2 - start_end.z1);
	vars->steps = fmax(vars->dx, vars->dy);
	vars->err = vars->dx - vars->dy;
	vars->dz /= vars->steps;
}
void draw_line(int32_t *pixels, int width, Draw start_end, int color)
{
	LineVars vars;

	initiate_vars(&vars, start_end);
	while (1)
	{
		// int color = interpolate_color(color_start, color_end, z);
		pixels[start_end.y1 * width + start_end.x1] = color;
		if (start_end.x1 == start_end.x2 && start_end.y1 == start_end.y2)
			break;
		vars.e2 = 2 * vars.err;
		if (vars.e2 > -vars.dy)
		{
			vars.err -= vars.dy;
			start_end.x1 += vars.sx;
		}
		if (vars.e2 < vars.dx)
		{
			vars.err += vars.dx;
			start_end.y1 += vars.sy;
		}
		start_end.z1 += vars.dz; // Interpolate z
	}
}

