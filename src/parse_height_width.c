/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_height_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/29 14:38:43 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	check_errors(t_map *map, int *fd, char *arr, int error)
{
	if (error == 1)
		exit_error(map, fd, 2, MALLOC);
	if (!arr)
		exit_error(map, fd, 2, MAP);
}

int	get_height(t_map *map, int *fd)
{
	char	*arr;
	int		height;
	int		error;

	error = 0;
	height = 0;
	arr = get_next_line(fd[1], &error);
	check_errors(map, fd, arr, error);
	while (arr)
	{
		free(arr);
		arr = NULL;
		arr = get_next_line(fd[1], &error);
		if (error == 1)
			exit_error(map, fd, 2, MALLOC);
		height += 1;
	}
	if (height <= 1)
		exit_error(map, fd, 2, MAP);
	return (height);
}

int	calc_width(char *arr)
{
	int	i;
	int	width;

	width = 0;
	i = 0;
	while (arr[i] && arr[i] != '\n')
	{
		while (ft_isspace(arr[i]))
			i++;
		if (arr[i] > 32 && arr[i] < 127)
		{
			while (arr[i] > 32 && arr[i] < 127)
				i++;
			width++;
		}
	}
	return (width);
}

int	get_width(t_map *map, int *fd)
{
	char	*arr;
	int		width;
	int		comp_width;
	int		error;

	error = 0;
	arr = get_next_line(fd[0], &error);
	check_errors(map, fd, arr, error);
	width = calc_width(arr);
	while (arr)
	{
		comp_width = calc_width(arr);
		free(arr);
		arr = NULL;
		if (comp_width != width)
			exit_error(map, fd, 2, MAP);
		arr = get_next_line(fd[0], &error);
		if (error == 1)
			exit_error(map, fd, 2, MALLOC);
	}
	if (width <= 1)
		exit_error(map, fd, 2, MAP);
	return (width);
}
