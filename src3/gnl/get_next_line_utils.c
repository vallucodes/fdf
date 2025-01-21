/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:15:41 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/01 23:49:44 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
