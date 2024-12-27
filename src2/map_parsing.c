/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:25:13 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/23 17:04:30 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_data()
{

}

int	open_directory(char *dictionary_name)
{
	int	fd;

	fd = open(dictionary_name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		return (NULL);
	}
	return (fd);
}

void	map_parsing()
{
	int fd;

	fd = open_file();
	load_data();

	close(fd);
}
