/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:20:21 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/17 13:10:21 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

double	ft_power(double n, int power)
{
	return (power ? n * ft_power(n, power - 1) : 1);
}

static void		ldtoa_fill(double n, t_printf *p, long value)
{
	int		len;
	int		i;
	char	s[48];

	len = p->lenofprint - 1 - p->prec;
	i = p->prec > 0 ? p->lenofprint : -1;
	while (i-- && p->prec > 0)
	{
		s[i ] = value % 10 + '0';
		value /= 10;
	}
	(p->prec > 0) ? s[len] = '.' : 0;
	value = (long)(FT_ABS(n));
	while (++i < len)
	{
		s[len - i - 1] = value % 10 + '0';
		value /= 10;
	}
	//(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
	(p->bit & FL_SPACE) ? buffer(p, " ", 1) : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->bit & FL_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(p, s, p->lenofprint);
}

int	f_flag(t_printf *p)
{
	double		n;
	long		tmp;
	int			len;
	double		decimal;
	long		value;

	n = (double)va_arg(p->ap, double);
	//(p->f & F_ZERO) ? p->precision = p->min_length : 0;

	p->prec = p->prec == -1 ? 6 : p->prec;
    tmp = (long)(FT_ABS(n));
    if (n < 0)
        len = 1 + ((tmp == 0) ? 1 : 0);
    else
        len = ((tmp == 0) ? 1 : 0) + (p->bit & FL_PLUS ? 1 : 0);
    while (tmp && ++len)
        tmp /= 10;
    //(p->bit & F_ZERO) ? p->prec = p->min_length : 0;
	p->lenofprint = p->prec + len + (p->prec > 0 ? 1 : 0);
	decimal = ((n < 0.0f) ? -n : n);
	decimal = (decimal - (long) decimal) * ft_power(10, p->prec + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	value = (int)decimal;
	ldtoa_fill(n, p, value);
	return (0);
}