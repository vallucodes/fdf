/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:55:23 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/12 19:06:45 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putchar(int a, int fd)
{
	char	c;

	c = '0' + a;
	ft_putchar_fd(c, fd);
}

static	void	ft_recursion(int nb, int fd)
{
	if (nb >= 10)
		ft_recursion(nb / 10, fd);
	ft_putchar(nb % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_recursion(n, fd);
}
