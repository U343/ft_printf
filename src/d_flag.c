/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:37:22 by wanton            #+#    #+#             */
/*   Updated: 2020/03/09 15:46:47 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		d_flag(t_printf *p/*, int w, int pres*/)
{
	int		n;
	char	*res;

	n = va_arg(p->ap, int);
	res = ft_itoa(n);
	while (*res)
		buffer(p, res++, 1);
	return (0);
}