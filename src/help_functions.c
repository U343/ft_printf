/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:59:51 by wanton            #+#    #+#             */
/*   Updated: 2020/05/12 16:00:25 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Function writing string s to buffer
** Conditions check zero value and zero round, with this parameters, result
** don't print
*/

void	res_to_buff(char *s, t_printf *p)
{
	char	*tmp;

	if (p->prec == 0 && p->bit & ZERO_VALUE)
		return ;
	tmp = s;
	while (*tmp)
		buffer(p, tmp++, 1);
}

/*
** Auxiliary function for ft_unsig_itoa_base()
** Меняет знак для отрицательных чисел и устанавливает соответствующий флаг.
** т.е. в дальнейшем число рассматривается как положительное, а знак
** печатается отдельно, в зависимости от флага
*/

char	*check_znak(long long value, t_printf *p, int base, int format)
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
	return (ft_unsig_itoa_base(tmp, base, format));
}

/*
** Function for parser.c / parse_width
*/

void	true_asterisk_width(t_printf *p, int spec)
{
	char	*str_spec;

	if (spec < 0)
	{
		p->bit |= 1 << 3;
		spec *= -1;
	}
	p->w = spec > 1 ? spec : 1;
	str_spec = ft_itoa(spec);
	while ((*str_spec >= '0') && (*str_spec <= '9'))
		++str_spec;
}

/*
** Function for parser.c / parse_prec
*/

void	true_asterisk_prec(t_printf *p, int prec)
{
	char	*str_prec;

	p->prec = prec >= 1 ? prec : 0;
	str_prec = ft_itoa(prec);
	while ((*str_prec >= '0') && (*str_prec <= '9'))
		++str_prec;
}

/*
** Function for parser.c / parse_size
*/

void	parse_size_continue(t_printf *p)
{
	if (*p->format == 'h')
	{
		if (p->format[1] == 'h' && ++p->format)
		{
			p->bit |= 1 << 9;
			p->format++;
		}
		else
		{
			p->bit |= 1 << 8;
			p->format++;
		}
	}
	else if (*p->format == 'L')
	{
		p->bit |= 1 << 15;
		p->format++;
	}
}
