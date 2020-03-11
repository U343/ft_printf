/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:37:22 by wanton            #+#    #+#             */
/*   Updated: 2020/03/11 16:06:57 by wanton           ###   ########.fr       */
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
	size_t	tmp2;

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
		{
			//ft_putstr("ok5\n");
			buffer(p, " ", 1);
		}
		width++;
	}
	if (ft_strrchr(p->flag, '+'))
		width--;
	//printf("c = %s\n", c);
	//printf("size = %d; width = %d\n", (int)size, width);
	while (width-- > tmp1)
	{
		//ft_putstr("ok5\n");
		buffer(p, c, 1);
	}
}

void	print_round(t_printf *p, size_t size)
{
	size_t		round;

	round = p->prec;
	if (ft_strrchr(p->flag, '+'))
		buffer(p, "+", 1);
	while (round-- > size)
		buffer(p, "0", 1);
}

int		d_flag(t_printf *p)
{
	int		n;
	char	*res;
	size_t	size;

	n = va_arg(p->ap, int);
	ft_putstr("prec = ");
	ft_putnbr(p->prec);
	ft_putchar('\n');
	res = ft_itoa(n);
	size = ft_strlen(res);
	//printf("size = %d:\n", (int)size);
	if (!ft_strrchr(p->flag, '-'))
	{
		//ft_putstr("ok\n");
		print_width(p, size);
	}
	print_round(p, size);
	add_to_buff(res, p);
	if (ft_strrchr(p->flag, '-'))
	{
		//ft_putstr("ok3\n");
		print_width(p, size);
	}
	return (0);
}