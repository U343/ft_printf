/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:18:57 by wanton            #+#    #+#             */
/*   Updated: 2020/03/11 14:45:25 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		s_flag(t_printf *p)
{
	char *res;
	int i;

	i = 0;
	res = va_arg(p->ap, char*);
	if ((p->bit & FL_MINUS) > 0)
	{
		while (*res && ((i++ < p->prec) || (p->prec == -1)))
			buffer(p, res++, 1);
		while (i++ < p->w)
			buffer(p, " ", 1);
	}
	else
	{
		while (i++ <= (int)(p->w - ft_strlen(res)))
			buffer(p, " ", 1);
		i = 0;
		while (*res && ((i++ < p->prec) || (p->prec == -1)))
			buffer(p, res++, 1);
	}
	return (0);
}
