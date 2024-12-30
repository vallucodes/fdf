/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:36:38 by vlopatin          #+#    #+#             */
/*   Updated: 2024/12/30 15:24:38 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// this is under the work, segfaulting, needs debugging.
// Just added double pointer to static

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;
	int		i;

	len = ft_strlen(s) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

void	fill_str(char *dst, const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc((1 + len) * sizeof(char));
	if (!dst)
		return (NULL);
	fill_str(dst, s1, s2);
	return (dst);
}

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
	static char	**str_s;

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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    int     fd[3];
    char    *line;

    fd[0] = open("10-2.fdf", O_RDONLY);
    if (fd[0] == -1)
    {
        perror("Error opening file");
        return 1;
    }

	fd[1] = open("10-70.fdf", O_RDONLY);
    if (fd[1] == -1)
    {
        perror("Error opening file");
        return 1;
    }

	fd[2] = open("elem.fdf", O_RDONLY);
    if (fd[2] == -1)
    {
        perror("Error opening file");
        return 1;
    }

	int i = 20;
	int j = 0;
	while (i > 0)
    {
        printf("round %i\n", i);
		line = get_next_line(fd[j]);
        printf("Line %s", line);
		j++;
		if (j == 3)
			j = 0;
        free(line);
        i--;
    }
    i = 2;
    while (i >= 0)
        close(fd[i]);
    return 0;
}


