/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:26:24 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/18 15:24:50 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	int	ft_count_words(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			w++;
		}
		else
			i++;
	}
	return (w);
}

static	void	ft_fill(char *dst1, char const *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dst1[i] = src[i];
		i++;
	}
	dst1[i] = 0;
}

static	int	ft_allocate_mem_word(char ***dst, int word_len, int j)
{
	(*dst)[j] = (char *)malloc(1 + word_len * sizeof(char));
	if (!(*dst)[j])
	{
		while (j > 0)
		{
			j--;
			free((*dst)[j]);
		}
		free(*dst);
		*dst = NULL;
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	dst = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			if (!ft_allocate_mem_word(&dst, ft_word_len(&s[i], c), j))
				return (NULL);
			ft_fill(dst[j++], &s[i], c);
			i += ft_word_len(&s[i], c);
		}
	}
	dst[j] = NULL;
	return (dst);
}
