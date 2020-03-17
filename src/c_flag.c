/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:20:21 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/17 13:10:21 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		my_minc(int len, int prec)
{
	if (len <= prec || prec == -1)
		return (len);
	else
		return (prec);
}

int	c_flag(t_printf *p)
{
	char res;
	int i;

	res = va_arg(p->ap, int);
	i = 0;
	if ((p->bit & FL_MINUS) > 0)
	{
		if (/*res && */((i < p->prec) || (p->prec <= 0)))
		{
			buffer(p, (char *)&res, 1);
			i++;
		}
		while (i++ < p->w && p->is_w)
			buffer(p, " ", 1);
	}
	else
	{
		while (p->is_w && 
			(i++ < (int)(p->w - (my_minc(1,p->prec)))))
			buffer(p, " ", 1);
		i = 0;
		if (/*res &&*/((i++ < p->prec) || (p->prec <= 0)))
			buffer(p, (char *)&res, 1);
	}
	return (0);
}