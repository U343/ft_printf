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

long	ft_abs(long a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

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
** Changing sign for negative numbers and set up appropriate flag
** so hereinafter, the number is considered as positive, and the sign
** printed separately, depending on the flag
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
	if (spec < 0)
	{
		p->bit |= 1 << 3;
		spec *= -1;
	}
	p->w = spec > 1 ? spec : 1;
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
