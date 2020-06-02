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

int			ft_ones(int i)
{
	return (1 + i - i);
}

int			my_min(int len, int prec)
{
	if (len <= prec || prec == -1)
		return (len);
	else
		return (prec);
}

int			s_flag(t_printf *p)
{
	char	*res;
	char	*c;
	int		i;

	i = 0;
	if (!(res = va_arg(p->ap, char*)))
		res = "(null)";
	c = ((p->bit & FL_ZERO) > 0) ? "0" : " ";
	if ((p->bit & FL_MINUS) > 0)
	{
		while (*res && ((i < p->prec) || (p->prec == -1)))
			buffer(p, res++, ft_ones(i++));
		while (i++ < p->w && p->is_w)
			buffer(p, " ", 1);
	}
	else
	{
		while (p->is_w &&
			(i++ < (int)(p->w - my_min((int)ft_strlen(res), p->prec))))
			buffer(p, c, 1);
		i = 0;
		while (*res && ((i++ < p->prec) || (p->prec == -1)))
			buffer(p, res++, 1);
	}
	return (0);
}
