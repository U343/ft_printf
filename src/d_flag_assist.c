/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag_assist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:20:21 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/17 13:10:21 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Function check flags for width and take special symbol.
** "Special symbol" it is symbol which will be print print_width()
** Symbol can be '0' or ' '
** Returned: symbol for print_width()
*/

char	*width_symbol(t_printf *p)
{
	if (p->bit & FL_ZERO && !(p->bit & FL_MINUS))
		return ("0");
	return (" ");
}

/*
** Пересчитывает параметр width, в зависимости от флагов
*/

void	calculating_width(t_printf *p)
{
	if ((p->bit & FL_PLUS || p->bit & NUM_MINUS || p->bit & CHECK_P)
	&& p->type != 'x' && p->type != 'X')
	{
		p->w--;
		p->bit &= ~CHECK_P;
	}
	else if ((p->bit & FL_SHARP || p->bit & CHECK_U) && (p->type == 'x' ||
	p->type == 'X' || p->type == 'o') && !(p->bit & ZERO_VALUE))
	{
		p->w -= (p->type == 'x' || p->type == 'X' ? 2 : 0);
		p->w -= (p->type == 'o' ? 1 : 0);
		p->prec -= (p->type == 'o' ? 1 : 0);
		p->bit &= ~CHECK_P;
	}
}

/*
** Continues the take_symbol_continue()
*/

void	take_symbol_continue(t_printf *p)
{
	if (p->bit & FL_SHARP && p->type == 'X' && !(p->bit & ZERO_VALUE))
	{
		buffer(p, "0", 1);
		buffer(p, "X", 1);
		p->bit &= ~FL_SHARP;
		p->bit |= CHECK_U;
	}
	if (p->bit & FL_SHARP && p->type == 'o' &&
		(!(p->bit & ZERO_VALUE) || p->prec == 0))
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

/*
** Отправляет в буффер символы, запрашиваемые флагами
*/

void	take_symbol(t_printf *p)
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
	take_symbol_continue(p);
}

/*
** Функция check_first_space() далает 2 вещи:
** 1 - обрабатывает случай когда округление = 0 и входное значение = 0.
** При этих параметрах, printf не должени выводить значение.
** 2 - обрабатывает флаг " " для d и i
** Все вышеперечисленные действия происходят за счет изменения параметра size
*/

int		check_first_space(t_printf *p, int size)
{
	if (p->bit & ZERO_VALUE && p->prec == 0)
	{
		size = 0;
		p->w = (p->w == 1 ? 0 : p->w);
	}
	if (p->bit & FL_SPACE && !(p->bit & FL_PLUS) && !(p->bit & NUM_MINUS) &&
		(p->type == 'd' || p->type == 'i'))
	{
		buffer(p, " ", 1);
		p->w--;
	}
	return (size);
}
