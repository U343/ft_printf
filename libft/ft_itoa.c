/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:04:56 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/13 15:36:39 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	length_int(int x)
{
	size_t		len;

	len = 1;
	while (x / 10)
	{
		x = x / 10;
		len++;
	}
	return (len);
}

static	size_t	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	size_t	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	i = length_int(n) + sign;
	if ((res = ft_strnew(i)))
	{
		res[i] = '\0';
		if (sign)
			res[0] = '-';
		if (!n)
			res[0] = '0';
		while (i > sign)
		{
			res[--i] = '0' + ft_abs(n % 10);
			n = n / 10;
		}
	}
	return (res);
}
