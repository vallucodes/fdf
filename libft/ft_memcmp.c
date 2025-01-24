/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:55:03 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/12 19:05:55 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_te;
	unsigned char	*s2_te;

	s1_te = (unsigned char *)s1;
	s2_te = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_te[i] != s2_te[i])
			return (((unsigned char *)s1_te)[i] - ((unsigned char *)s2_te)[i]);
		i++;
	}
	return (0);
}
