/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:47:28 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/04 22:33:30 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	char	t;
	int		s;

	div = 1;
	s = 1;
	if (n < 0)
	{
		s = -1;
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			n = -147483648;
			write(fd, "2", 1);
		}
	}
	while (n / div > 9 || n / div < -9)
		div = div * 10;
	while (div)
	{
		t = '0' + s * n / div;
		write(fd, &t, 1);
		n = n % div;
		div = div / 10;
	}
}
