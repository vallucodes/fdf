/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:28:33 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/12 19:07:41 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_find_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	match_flag;
	int	start_flag;

	match_flag = 0;
	start_flag = -1;
	i = 0;
	while (s1[i] && start_flag == -1)
	{
		j = 0;
		match_flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				match_flag = 1;
			j++;
		}
		if (match_flag == 0)
			start_flag = i;
		i++;
	}
	return (start_flag);
}

static	int	ft_find_end(char const *s1, char const *set, int start_flag)
{
	int				j;
	int				match_flag;
	unsigned long	end_flag;
	int				len;

	len = ft_strlen(s1);
	end_flag = ft_strlen(s1);
	while (len > start_flag && end_flag == ft_strlen(s1))
	{
		j = 0;
		match_flag = 0;
		len--;
		while (set[j])
		{
			if (s1[len] == set[j])
				match_flag = 1;
			j++;
		}
		if (match_flag == 0)
			end_flag = len;
	}
	return (end_flag);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_flag;
	int		end_flag;
	size_t	size;
	char	*dst;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_flag = ft_find_start(s1, set);
	end_flag = ft_find_end(s1, set, start_flag);
	size = 2 + (end_flag - start_flag);
	if (start_flag == -1 && end_flag == -1)
		size = 1;
	if (s1[0] == '\0')
		start_flag = 0;
	dst = (char *)ft_calloc(size, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcat(dst, &s1[start_flag], size);
	return (dst);
}
