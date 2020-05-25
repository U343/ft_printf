/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:14:08 by wanton            #+#    #+#             */
/*   Updated: 2020/03/17 12:59:15 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static __uint128_t	ft_pow(long long nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char				*ft_itoa_base(long long value, int base, int format)
{
	int			i;
	int			neg;
	char		*nbr;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if ((unsigned long long)value == -9223372036854775808u)
			return ("-9223372036854775808");
		neg = (base == 10) ? 1 : neg;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < (__uint128_t)value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ?
			('A' + format) - 10 : '0');
		value = value / base;
	}
	nbr[0] = (neg) ? '-' : nbr[0];
	return (nbr);
}
