/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:36:38 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/02 14:14:16 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line(int fd, char *str_s, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		if (!str_s)
			str_s = ft_strdup("");
		buffer[bytes_read] = '\0';
		temp = str_s;
		str_s = ft_strjoin(str_s, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(str_s, '\n'))
			break ;
	}
	return (str_s);
}

static char	*set_reminder(char *line)
{
	char		*str_s;
	ssize_t		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
	{
		str_s = ft_strdup(&line[i + 1]);
		if (*str_s == '\0')
		{
			free(str_s);
			str_s = NULL;
		}
		line[i + 1] = '\0';
		return (str_s);
	}
	str_s = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*str_s[MAX_FD];

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = fill_line(fd, str_s[fd], buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	str_s[fd] = set_reminder(line);
	return (line);
}
