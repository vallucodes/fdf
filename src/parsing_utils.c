/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:48:30 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/24 10:58:11 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_alnum(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	clear_fd(int fd)
{
	char *arr;
	arr = get_next_line(fd);
	while (arr)
	{
		free(arr);
		arr = get_next_line(fd);
	}
	free(arr);
}

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

int	get_width(int fd)
{
	char	*arr;
	int		i;
	int		width;

	arr = get_next_line(fd);
	if (!arr)
		return (0);
	i = 0;
	width = 0;
	while(arr[i] && arr[i] != '\n')
	{
		while(arr[i] == ' ')
			i++;
		if (arr[i] > 32 && arr[i] < 127)
		{
			while(arr[i] > 32 && arr[i] < 127)
				i++;
			width++;
		}
	}
	free(arr);
	clear_fd(fd);
	return (width);
}
