// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_main.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/11 16:44:47 by vlopatin          #+#    #+#             */
// /*   Updated: 2024/12/11 16:50:10 by vlopatin         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// // #include <.h>
// #include "../include/fdf.h"

// static int	dx(int x1, int x2)
// {
// 	if (x2 > x1)
// 		return (x2 - x1);
// 	else
// 		return (-(x2 - x1));
// }

// static int	sx(int x1, int x2)
// {
// 	if (x1 > x2)
// 		return (-1);
// 	else
// 		return (1);
// }

// static int	dy(int y1, int y2)
// {
// 	if (y2 > y1)
// 		return (-(y2 - y1));
// 	else
// 		return (y2 - y1);
// }

// static int	sy(int y1, int y2)
// {
// 	if (y1 > y2)
// 		return (-1);
// 	else
// 		return (1);
// }

// void	draw_line(signed int *pixels, int width, int x1, int y1, int x2, int y2, int color)
// {
// 	LineVars	vars;
// 	int			err;
// 	int			e2;

// 	vars.dx = dx(x1, x2);
// 	vars.sx = sx(x1, x2);
// 	vars.dy = dy(y1, y2);
// 	vars.sy = sy(y1, y2);
// 	err = vars.dx + vars.dy;
// 	while (!(x1 == x2 && y1 == y2))
// 	{
// 		pixels[y1 * width + x1] = color;
// 		e2 = 2 * err;
// 		if (e2 >= vars.dy)
// 		{
// 			err += vars.dy;
// 			x1 += vars.sx;
// 		}
// 		if (e2 <= vars.dx)
// 		{
// 			err += vars.dx;
// 			y1 += vars.sy;
// 		}
// 	}
// }

// int main()
// {
// 	int *pixels = calloc(1000 * 1000, sizeof(int));

// 	draw_line(pixels, 1000, 200, 500, 100, 500, 0xFF0000FF);
// }
