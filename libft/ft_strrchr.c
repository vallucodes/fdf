/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:54:20 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/12 19:07:38 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurance;

	last_occurance = 0;
	while (*s)
	{
		if (*s == (char)c)
			last_occurance = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last_occurance);
}
