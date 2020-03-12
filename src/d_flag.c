/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:37:22 by wanton            #+#    #+#             */
/*   Updated: 2020/03/12 13:59:06 by wanton           ###   ########.fr       */
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

void		print_width(t_printf *p, size_t size, int *f_p)
{
	char	*c;
	size_t	width;
	size_t	tmp1;

	width = p->w;
	if (((p->bit & FL_ZERO) > 0) && !((p->bit & FL_MINUS) > 0))
		c = "0";
	else
		c = " ";
	tmp1 = size;
	if (((p->bit & FL_PLUS) > 0) && (p->type != 'x' && p->type != 'X'))
		width--;
	if (p->prec != -1 && p->prec > 0)
	{
		tmp1 = size > (size_t)p->prec ? size : p->prec;
		while (width-- > tmp1)
			buffer(p, " ", 1);
		width++;
	}
	if (((p->bit & FL_PLUS) > 0) && ft_strcmp(c, "0") == 0 && (*f_p) == 0
	&& (p->type != 'x' && p->type != 'X'))
	{
		buffer(p, "+", 1);
		*f_p = 1;
	}
	while (width-- > tmp1)
		buffer(p, c, 1);
}

void		print_round(t_printf *p, size_t size, int *f_p)
{
	size_t	round;

	if (((p->bit & FL_PLUS) > 0) && (*f_p) == 0
	&& (p->type != 'x' && p->type != 'X'))
	{
		buffer(p, "+", 1);
		(*f_p) = 1;
	}
	if (p->prec < 0)
		return ;
	round = p->prec;
	while (round-- > size)
		buffer(p, "0", 1);
}

/*
**Function call va_arg for different decimal types
**       Returned: result of the va_arg
*/


long long	check_type_size(t_printf *p)
{
	char	*size;

	size = p->size;
	if (ft_strcmp(size, "ll") == 0)
		return (va_arg(p->ap, long long));
	else if (ft_strcmp(size, "hh") == 0)
		return ((long long)va_arg(p->ap, int));
	else if (ft_strcmp(size, "l") == 0)
		return (va_arg(p->ap, long));
	else if (ft_strcmp(size, "h") == 0)
		return ((long long)va_arg(p->ap, int));
	else
		return ((long long)va_arg(p->ap, int));
}

/*
**Function for print d, ld, lld, hd and hhd
** format - value fo xX flags: 0 for X and 32 for x
**       Returned: 0 if successful
*/

int			d_flag(t_printf *p)
{
	int		flag_plus;
	int		format;
	int		base;
	char	*res;
	size_t	size;

	flag_plus = 0;
	
	format = (p->type == 'x' ? 32 : 0);
	base = (p->type == 'x' || p->type == 'X' ? 16 : 10);
	res = ft_itoa_base(check_type_size(p), base, format);
	size = ft_strlen(res);
	if (!((p->bit & FL_MINUS) > 0))
		print_width(p, size, &flag_plus);
	print_round(p, size, &flag_plus);
	add_to_buff(res, p);
	if ((p->bit & FL_MINUS) > 0)
		print_width(p, size, &flag_plus);
	return (0);
}
