/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:37:22 by wanton            #+#    #+#             */
/*   Updated: 2020/03/11 17:29:00 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	add_to_buff(char *s, t_printf *p)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
		buffer(p, tmp++, 1);
}

void	print_width(t_printf *p, size_t size)
{
	char	*c;
	size_t 	width;
	size_t	tmp1;

	width = p->w;
	if (ft_strrchr(p->flag, '0') && !ft_strrchr(p->flag, '-'))
		c = "0";
	else
		c = " ";
	tmp1 = size;
	if (p->prec != -1 && p->prec > 0)
	{
		tmp1 = size > (size_t)p->prec ? size : p->prec;
		while (width-- > tmp1)
			buffer(p, " ", 1);
		width++;
	}
	if (ft_strrchr(p->flag, '+'))
		width--;
	while (width-- > tmp1)
		buffer(p, c, 1);
}

void	print_round(t_printf *p, size_t size)
{
	size_t	round;

	/*if (ft_strrchr(p->flag, '+'))
		buffer(p, "+", 1);*/
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
**       Returned: 0 if successful
*/

int			d_flag(t_printf *p)
{
	char	*res;
	size_t	size;

	ft_putstr("in d_flag\n");  //delete
	ft_putendl(p->flag);
	res = ft_itoall(check_type_size(p));
	size = ft_strlen(res);
	if (!ft_strrchr(p->flag, '-'))
		print_width(p, size);
	print_round(p, size);
	add_to_buff(res, p);
	if (ft_strrchr(p->flag, '-'))
		print_width(p, size);
	return (0);
}