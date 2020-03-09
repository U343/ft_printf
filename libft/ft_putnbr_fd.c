/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:17:21 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/13 12:24:11 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nn;

	if (n < 0)
		ft_putchar_fd('-', fd);
	nn = (unsigned int)ft_abs(n);
	if (nn / 10)
		ft_putnbr_fd(nn / 10, fd);
	ft_putchar_fd('0' + nn % 10, fd);
}
