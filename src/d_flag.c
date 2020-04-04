/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:37:22 by wanton            #+#    #+#             */
/*   Updated: 2020/03/17 15:05:34 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		add_to_buff(char *s, t_printf *p)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
		buffer(p, tmp++, 1);
}

char 		*check_znak(long long value, t_printf *p, int base, int format)
{
	unsigned long long	tmp;

	if (value == 0)
        p->bit |= ZERO_VALUE;
	if (value < 0)
	{
		if ((unsigned long long)value == -9223372036854775808u)
			return ("-9223372036854775808");
		if (base == 10)
		{
			p->bit |= NUM_MINUS;
			p->bit &= ~FL_PLUS;
		}
		value *= -1;
	}
	tmp = (unsigned long long)value;
	return (ft__unsig_itoa_base(tmp, base, format));
}

void		take_symbol(t_printf *p)
{
	if (p->bit & FL_PLUS && (p->type == 'd' || p->type == 'i'))
	{
		buffer(p, "+", 1);
		p->bit &= ~FL_PLUS;
		p->bit |= CHECK_P;
	}
	if (p->bit & FL_SHARP && p->type == 'x' && !(p->bit & ZERO_VALUE))
	{
		buffer(p, "0", 1);
		buffer(p, "x", 1);
		p->bit &= ~FL_SHARP;
		p->bit |= CHECK_U;
	}
	if (p->bit & FL_SHARP && p->type == 'X' && !(p->bit & ZERO_VALUE))
	{
		buffer(p, "0", 1);
		buffer(p, "X", 1);
		p->bit &= ~FL_SHARP;
		p->bit |= CHECK_U;
	}
    if (p->bit & FL_SHARP && p->type == 'o' && !(p->bit & ZERO_VALUE))
    {
        buffer(p, "0", 1);
        p->bit &= ~FL_SHARP;
        p->bit |= CHECK_U;
    }
	if (p->bit & NUM_MINUS)
	{
		p->bit &= ~NUM_MINUS;
		buffer(p, "-", 1);
		p->bit |= CHECK_P;
	}
}

void		print_width(t_printf *p, size_t size)
{
	char	*c;
	size_t	tmp1;

	if (((p->bit & FL_ZERO) > 0) && !((p->bit & FL_MINUS) > 0))
		c = "0";
	else
		c = " ";
	tmp1 = size;
	if ((p->bit & FL_PLUS || p->bit & NUM_MINUS || p->bit & CHECK_P)
	&& p->type != 'x' && p->type != 'X')
	{
		p->w--;
		p->bit &= ~CHECK_P;
	}
	else if (p->bit & FL_SHARP && (p->type == 'x' || p->type == 'X' ||
			p->bit & CHECK_U || p->type == 'o') && !(p->bit & ZERO_VALUE))
	{
		p->w -= (p->type == 'x'|| p->type == 'X' ? 2 : 0);
        p->w -= (p->type == 'o' ? 1 : 0);
		p->bit &= ~CHECK_P;
	}
	if (p->prec != -1 && p->prec > 0)
	{
		tmp1 = size > (size_t)p->prec ? size : p->prec;
		while ((size_t)p->w-- > tmp1)
			buffer(p, " ", 1);
		p->w++;
	}
	if (ft_strcmp(c, "0") == 0)
		take_symbol(p);
	while (p->w > 0 && (size_t)p->w-- > tmp1)
		buffer(p, c, 1);
}

void		print_round(t_printf *p, size_t size)
{
	size_t	round;

	take_symbol(p);
	if (p->prec < 0)
		return ;
	round = p->prec;
	while (round-- > size)
		buffer(p, "0", 1);
}

char	*unsig_format(t_printf *p, int base, int format)
{
	unsigned long long	res;

	if (p->bit & FL_LL)
		res = va_arg(p->ap, unsigned long long);
	else if (p->bit & FL_HH)
		res = (unsigned char)va_arg(p->ap, unsigned int);
	else if (p->bit & FL_L)
		res = va_arg(p->ap, unsigned long);
	else if (p->bit & FL_H)
		res = (unsigned short)va_arg(p->ap, unsigned int);
	else
		res = va_arg(p->ap, unsigned int);
    if (res == 0)
        p->bit |= ZERO_VALUE;
	return (ft__unsig_itoa_base(res, base, format));
}

/*
**Function call va_arg for different decimal types
**       Returned: result of the va_arg
*/

char	*check_type_size(t_printf *p, int base, int format)
{
	long long	res;

	if (p->type != 'd' && p->type != 'i')
		return (unsig_format(p, base, format));
	if (p->bit & FL_LL)
		res = va_arg(p->ap, long long);
	else if (p->bit & FL_HH)
		res = (char)va_arg(p->ap, int);
	else if (p->bit & FL_L)
		res = va_arg(p->ap, long);
	else if (p->bit & FL_H)
		res = (short)va_arg(p->ap, int);
	else
		res = (long long)va_arg(p->ap, int);
	res = (long long)res;
	return (check_znak(res, p, base, format));
}

/*
**Function for print d, ld, lld, hd and hhd
** format - value fo xX flags: 0 for X and 32 for x
**       Returned: 0 if successful
*/

int			d_flag(t_printf *p)
{
	int		format;
	int		base;
	char	*res;
	size_t	size;

	//ft_putstr("d_flag1\n");
	format = (p->type == 'x' ? 32 : 0);
	base = (p->type == 'x' || p->type == 'X' ? 16 : 10);
	base = (p->type == 'o' ? 8 : base);
	res = check_type_size(p, base, format);
	size = ft_strlen(res);
	if (!(p->bit & FL_MINUS))
		print_width(p, size);
	print_round(p, size);
	add_to_buff(res, p);
	if (p->bit & FL_MINUS)
		print_width(p, size);
	return (0);
}
