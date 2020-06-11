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

static void			fill_else(t_printf *p, char *s)
{
	buffer(p, s, p->lenofprint);
	(p->bit & FL_SHARP) && (p->prec <= 0) ? buffer(p, ".", 1) : 0;
}

static void			fill2(double n, t_printf *p, char *s, int i)
{
	(p->bit & FL_PLUS && n >= 0) ? s[0] = '+' : 0;
	i = p->w - p->lenofprint;
	if (p->w > p->lenofprint)
	{
		if (p->bit & FL_MINUS)
		{
			(p->bit & FL_SPACE) && (p->lenofprint <= p->w)
				&& (n >= 0) ? buffer(p, " ", p_one(i--)) : 0;
			buffer(p, s, p->lenofprint);
			(p->bit & FL_SHARP) &&
				(p->prec <= 0) ? buffer(p, ".", p_one(i--)) : 0;
			while (i--)
				buffer(p, " ", 1);
		}
		else
		{
			(p->bit & FL_SHARP) && (p->prec <= 0) ? i-- : 0;
			while (i--)
				buffer(p, " ", 1);
			buffer(p, s, p->lenofprint);
			(p->bit & FL_SHARP) && (p->prec <= 0) ? buffer(p, ".", 1) : 0;
		}
	}
	else
		fill_else(p, s);
}

static int			getiandzero(char *s, t_printf *p)
{
	int i;
	int j;

	i = 0;
	if (p->prec < 19)
		i = p->prec > 0 ? p->lenofprint - 1 : 1;
	else
	{
		i = 18 + p->lenofprint - 1 - p->prec;
		j = i;
		while (j < p->lenofprint)
			s[j++] = '0';
	}
	return (i);
}

static void			fill(double n, t_printf *p, long long value)
{
	int				len;
	int				i;
	char			*s;

	len = p->lenofprint - p->prec - (p->prec > 0 ? 1 : 0);
	s = ft_strnew(p->lenofprint);
	i = getiandzero(s, p);
	while (i > len && p->prec > 0)
	{
		s[i--] = value % 10 + '0';
		value /= 10;
	}
	value = (value) ? 1 : 0;
	p->prec > 0 ? s[len] = '.' : 0;
	value += (long long)(ft_abs(n));
	while (--i > -1)
	{
		s[i] = value % 10 + '0';
		value /= 10;
	}
	(p->bit & FL_SPACE) && (p->lenofprint >= p->w)
		&& (n >= 0) ? buffer(p, " ", 1) : 0;
	(n < 0) || (1 / n < 0) ? s[0] = '-' : 0;
	fill2(n, p, s, i);
	free(s);
}

int					f_flag(t_printf *p)
{
	long double		n;
	long long		tmp;
	int				len;
	long double		decimal;
	long long		value;

	n = (p->bit & FL_BIGL) ? (long double)va_arg(p->ap, long double) :
			(double)va_arg(p->ap, double);
	p->prec = p->prec == -1 ? 6 : p->prec;
	tmp = (long long)(ft_abs(n));
	if (n < 0)
		len = 1 + ((tmp == 0) ? 1 : 0);
	else
		len = ((tmp == 0) ? 1 : 0) + (p->bit & FL_PLUS ? 1 : 0);
	while (tmp && ++len)
		tmp /= 10;
	p->lenofprint = p->prec + len + (p->prec > 0 ? 1 : 0);
	decimal = ((n < 0.0f) ? -n : n);
	decimal = (decimal - (long long)decimal) * ft_power_d(10, p->prec + 1);
	decimal = (ft_abs((long long)decimal % 10) > 4) ?
		(decimal) / 10 + 1 : decimal / 10;
	value = (long long)decimal;
	fill(n, p, value);
	return (0);
}
