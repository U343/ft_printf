/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:18:57 by wanton            #+#    #+#             */
/*   Updated: 2020/03/09 14:28:15 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *s_flag(t_printf *p)
{
	char *res;

	res = va_arg(p->ap, char *);
	ft_putstr(res);
	return res;
}

