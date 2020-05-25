/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:20:21 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/17 13:10:21 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_flags(char *f[12])
{
	f[0] = "s";
	f[1] = "d";
	f[2] = "i";
	f[3] = "d";
	f[4] = "d";
	f[3] = "x";
	f[4] = "X";
	f[5] = "c";
	f[6] = "u";
	f[7] = "o";
	f[8] = "%";
	f[9] = "p";
	f[10] = "f";
	f[11] = NULL;
}

void	init_flag_func(int (*b[12]) (t_printf *p))
{
	b[0] = &s_flag;
	b[1] = &d_flag;
	b[2] = &d_flag;
	b[3] = &d_flag;
	b[4] = &d_flag;
	b[5] = &c_flag;
	b[6] = &d_flag;
	b[7] = &d_flag;
	b[8] = &pr_flag;
	b[9] = &p_flag;
	b[10] = &f_flag;
	b[11] = NULL;
}

void	init_struct(t_printf *p)
{
	p->bit = 0;
	p->w = 1;
	p->is_w = 0;
	p->prec = -1;
	p->size = "";
	p->type = 0;
}
