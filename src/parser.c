/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:55:16 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/09 15:29:05 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	init_flags(char *f[4])
{
	f[0] = "s";
	f[1] = "d";
	f[2] = "c";
	f[3] = NULL;
}

static void	init_flag_func(int (*b[4]) (t_printf *p))
{
	b[0] = &s_flag;
	b[1] = &d_flag;
	b[3] = NULL;
}

void		parse(t_printf *p)
{
	size_t 	i;
	char 	*flags[4];
	int 	(*builtin_func[4]) (t_printf *p);

	i = 0;
	init_flags(flags);
	init_flag_func(builtin_func);
	while (flags[i])
	{
		if ((ft_strncmp(p->format, flags[i], ft_strlen(flags[i])) == 0))
		{
			(*builtin_func[i])(p);
			p->format += (ft_strlen(flags[i]) - 1);
			break;
		}
		i++;
	}
}

