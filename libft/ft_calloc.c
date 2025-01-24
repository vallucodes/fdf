/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:03:59 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 19:02:23 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	result;

	result = nmemb * size;
	if (nmemb && size != result / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr != NULL)
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
