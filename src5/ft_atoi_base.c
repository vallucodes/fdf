/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:49:26 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/02 15:47:57 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

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
	while(is_space(str[i]))
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
