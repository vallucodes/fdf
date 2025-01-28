/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:30:06 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/28 12:31:24 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

void	exit_error(t_map *map, int *fd, int error, const char *msg)
{
	if (error == 0)
	{
		free (map->original);
		free (map->new2d);
		free (map);
	}
	else if (error == 1)
	{
		free (map->original);
		free (map->new2d);
		free (map);
		close_fds(fd, 3);
	}
	else if (error == 2)
	{
		free (map);
		close_fds(fd, 3);
	}
	ft_putendl_fd((char *)msg, 2);
	exit (1);
}
