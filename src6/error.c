/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:30:06 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/26 10:49:07 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	close_fds(int *fd, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (fd[i] != -1)
			close (fd[i]);
		fd[i] = -1;
		i++;
	}
}

void	exit_error(t_map *map, int *fd, int error)
{
	if (error == 1)
	{
		free (map->original);
		free (map->new2d);
		ft_putstr_fd("Memory allocation failed\n", 2);
		exit (1);
	}
	else if (error == 2)
	{
		close_fds(fd, 3);
		ft_putstr_fd("Invalid map\n", 2);
		exit (1);
	}
	else if (error == 3)
	{
		close_fds(fd, 3);
		ft_putstr_fd("Invalid file name\n", 2);
		exit (1);
	}
}
