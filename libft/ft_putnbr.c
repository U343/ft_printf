/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:07:29 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/13 12:23:46 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void		ft_putnbr(int n)
{
	unsigned int nn;

	if (n < 0)
		ft_putchar('-');
	nn = (unsigned int)ft_abs(n);
	if (nn / 10)
		ft_putnbr(nn / 10);
	ft_putchar('0' + nn % 10);
}
