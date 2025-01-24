/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:15:27 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/12 19:06:14 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst_temp;
	const char	*src_temp;

	dst_temp = (char *)dest;
	src_temp = (char *)src;
	if (dst_temp <= src_temp)
		ft_memcpy(dst_temp, src_temp, n);
	else if (src_temp < dst_temp)
	{
		dst_temp += n - 1;
		src_temp += n - 1;
		while (n > 0)
		{
			*dst_temp-- = *src_temp--;
			n--;
		}
	}
	return (dest);
}
