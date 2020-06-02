/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:20:21 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/17 13:10:21 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		my_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int		p_one(int a)
{
	return (1 + a - a);
}

void	if_minus(t_printf *p, char *str)
{
	int			i;

	i = 0;
	buffer(p, "0x", 2);
	while ((p->prec - (int)ft_strlen(str) - i) > 0)
		buffer(p, "0", p_one(i++));
	while (*str)
		buffer(p, str++, p_one(i++));
	while ((i++ < (p->w - 2)) && p->is_w)
		buffer(p, " ", 1);
}

void	if_not_minus(t_printf *p, char *str)
{
	int			i;

	i = 0;
	while (i++ < (p->w - (my_max((int)ft_strlen(str) + 2, p->prec + 2))))
		buffer(p, " ", 1);
	i = 0;
	buffer(p, "0x", 2);
	while ((int)ft_strlen(str) + i++ < p->prec)
		buffer(p, "0", 1);
	while (*str)
		buffer(p, str++, 1);
}

int		p_flag(t_printf *p)
{
	char		*str;
	char		*cpy;
	uintmax_t	num;

	num = (unsigned long)(va_arg(p->ap, unsigned long int));
	num = (uintmax_t)num;
	if (!(str = ft_itoa_base(num, 16, 32)))
		return (-1);
	if (p->prec == 0 && !num)
	{
		buffer(p, "0x", 2);
		free(str);
		return (0);
	}
	cpy = str;
	if ((p->bit & FL_MINUS) > 0)
		if_minus(p, str);
	else
		if_not_minus(p, str);
	free(cpy);
	return (0);
}
