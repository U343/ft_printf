/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:26:54 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/17 15:56:18 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;
	char				*s;

	result = 0;
	sign = 1;
	s = (char *)str;
	while ((*s == ' ') || ((*s > 8) && (*s < 14)))
		s++;
	if ((*s == '+') || (*s == '-'))
	{
		if (*s++ == '-')
			sign = -1;
	}
	while (ft_isdigit(*s))
		result = result * 10 + *s++ - 48;
	if (result > 9223372036854775807UL)
	{
		if (sign > 0)
			return (-1);
		else
			return (0);
	}
	return ((int)result * sign);
}
