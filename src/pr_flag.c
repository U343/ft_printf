/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:20:21 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/13 16:20:24 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		my_minp(int len, int prec)
{
	if (len <= prec || prec == -1)
		return (len);
	else
		return (prec);
}

int	pr_flag(t_printf *p)
{
	char res;
	int i;

	res = '%';
	i = 0;
	if ((p->bit & FL_MINUS) > 0)
	{
		if ((i < p->prec) || (p->prec <= 0))
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
			(i++ < (int)(p->w - (my_minp(1,p->prec)))))
			buffer(p, " ", 1);
		i = 0;
		if ((i++ < p->prec) || (p->prec <= 0))
			buffer(p, (char *)&res, 1);
	}
	return (0);
}