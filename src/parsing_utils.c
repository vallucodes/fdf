/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/28 11:29:54 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_height(t_map *map, int *fd)
{
	char	*arr;
	int		height;

	height = 0;
	arr = get_next_line(fd[1]);
	if (!arr)
		exit_error(map, fd, 2, MAP);
	while (arr)
	{
		free(arr);
		arr = NULL;
		arr = get_next_line(fd[1]);
		height += 1;
	}
	free(arr);
	arr = NULL;
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
	while(arr[i] && arr[i] != '\n')
	{
		while(ft_isspace(arr[i]))
			i++;
		if (arr[i] > 32 && arr[i] < 127)
		{
			while(arr[i] > 32 && arr[i] < 127)
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

	arr = get_next_line(fd[0]);
	if (!arr)
		exit_error(map, fd, 2, MAP);
	width = calc_width(arr);
	while (arr)
	{
		comp_width = calc_width(arr);
		free(arr);
		arr = NULL;
		if (comp_width != width)
			exit_error(map, fd, 2, MAP);
		arr = get_next_line(fd[0]);
	}
	free(arr);
	arr = NULL;
	if (width <= 1)
		exit_error(map, fd, 2, MAP);
	return (width);
}
