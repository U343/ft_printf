/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:45:48 by wanton            #+#    #+#             */
/*   Updated: 2020/03/11 16:45:48 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	length_int(long long x)
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

static	size_t	ft_abs(long long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char			*ft_itoall(long long n)
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
