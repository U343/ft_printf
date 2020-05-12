/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:59:51 by null              #+#    #+#             */
/*   Updated: 2020/05/12 16:00:25 by null             ###   ########.fr       */
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
