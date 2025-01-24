/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:16:33 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/12 19:06:26 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_temp;
	const unsigned char	*src_temp;

	if (!dest && !src)
		return (0);
	i = 0;
	dst_temp = (unsigned char *)dest;
	src_temp = (const unsigned char *)src;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dest);
}
