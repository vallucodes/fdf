/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:46:23 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/17 21:37:54 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_X(double *y, double *z)
{
	int i;
	int temp;
	double theta = atan(sqrt(1.0 / 2.0));
	temp = 0;
	i = 0;
	while (i < 4)
	{
		temp = y[i];
		y[i] = (temp * cos(theta) - z[i] * sin(theta));
		z[i] = (temp * sin(theta) + z[i] * cos(theta));
		i++;
	}
}

void	rotation_Y(double *x, double *z)
{
	int i;
	int temp;
	double theta = atan(sqrt(1.0 / 2.0));
	temp = 0;
	i = 0;
	while (i < 4)
	{
		temp = x[i];
		x[i] = (temp * cos(theta) + z[i] * sin(theta));
		z[i] = (temp * (-sin(theta)) + z[i] * cos(theta));
		i++;
	}
}

void	rotation_Z(double *x, double *y)
{
	int i;
	int temp;
	double theta = M_PI/8;
	temp = 0;
	i = 0;
	while (i < 4)
	{
		temp = x[i];
		x[i] = (temp * cos(theta) - y[i] * sin(theta));
		y[i] = (temp * sin(theta) + y[i] * cos(theta));
		i++;
	}
}
void	scale(Map map)
{
	map.width = SCALE * map.width;
	map.height = SCALE * map.height;
}
