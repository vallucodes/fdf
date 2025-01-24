/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:15:44 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/14 15:23:46 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	if (size == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	if (dest_len == size)
		return (dest_len + src_len);
	if (size - dest_len > src_len)
		ft_memcpy(dst + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dest_len, src, size - dest_len - 1);
		dst[size - 1] = '\0';
	}
	return (dest_len + src_len);
}
