/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/25 19:37:44 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_height(int fd)
{
	char	*arr;
	int		height;

	height = 0;
	arr = get_next_line(fd);
	if (!arr)
		return (0);
	while (arr)
	{
		free(arr);
		arr = get_next_line(fd);
		height += 1;
	}
	free(arr);
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
int	get_width(int *fd)
{
	char	*arr;
	int		width;
	int		comp_width;

	arr = get_next_line(fd[0]);
	if (!arr)
		return (0);
	width = calc_width(arr);
	while (arr)
	{
		comp_width = calc_width(arr);
		free(arr);
		if (comp_width != width)
			exit_error(NULL, fd, 2);
		arr = get_next_line(fd[0]);
	}
	free(arr);
	return (width);
}
