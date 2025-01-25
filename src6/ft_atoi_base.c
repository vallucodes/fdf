/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:49:26 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/25 15:07:57 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	is_valid(char c, int base)
{
	char digits[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char digits2[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while (base > 0)
	{
		base--;
		if(digits[base] == c || digits2[base] == c)
			return (1);
	}
	return (0);
}

static int	calc_nb(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (10 + c - 'a');
	else if (c >= 'A' && c <= 'Z')
		return (10 + c - 'A');
	return (0);
}

int32_t	ft_atoi_base(char *str, int base)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	i = 0;
	while(ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	res = 0;
	while(is_valid(str[i], base))
	{
		res = res * base + calc_nb(str[i]);
		i++;
	}
	return (res * sign);
}
