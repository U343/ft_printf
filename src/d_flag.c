/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:40:03 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/11 14:49:40 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Функция печатает "ширину" если это необходимо
** количество печатаемых символов рассчитывается на основе size
*/

void		print_width(t_printf *p, size_t size)
{
	char	*c;
	size_t	tmp1;

	c = width_symbol(p);
	tmp1 = size;
	if (p->prec > 0)
	{
		tmp1 = size > (size_t)p->prec ? size : p->prec;
		if (p->w > 0)
		{
			while (p->w-- > (int)tmp1)
				buffer(p, " ", 1);
			p->w++;
		}
	}
	if (ft_strcmp(c, "0") == 0)
		take_symbol(p);
	while (p->w > 0 && (size_t)p->w-- > tmp1)
		buffer(p, c, 1);
}

/*
** print_round() - добавляет '0' если округление больше размера числа
** take_symbol() - ставит префиксы и различные символы, запрашиваемые флагами
*/

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

/*
**Function call va_arg for o/x/X types
**ZERO_VALUE - флаг, нужен для того чтобы не ставить префикс
** для беззнаковых чисел, запрашиваемый флагом '#'
**       Returned: result of function ft_unsig_itoa_base()
*/

char		*unsig_format(t_printf *p, int base, int format)
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
	return (ft_unsig_itoa_base(res, base, format));
}

/*
**Function call va_arg for different decimal types
** and call unsig_format() for o/x/X flags
**       Returned: result of function check_znak()
*/

char		*check_type_size(t_printf *p, int base, int format)
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

	format = (p->type == 'x' ? 32 : 0);
	base = (p->type == 'x' || p->type == 'X' ? 16 : 10);
	base = (p->type == 'o' ? 8 : base);
	res = check_type_size(p, base, format);
	size = ft_strlen(res);
	size = check_first_space(p, size);
	calculating_width(p);
	if (!(p->bit & FL_MINUS))
		print_width(p, size);
	print_round(p, size);
	res_to_buff(res, p);
	if (p->bit & FL_MINUS)
		print_width(p, size);
	(res[0] != '-') ? free(res) : 0;
	return (0);
}
