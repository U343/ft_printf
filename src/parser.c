/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:55:16 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/09 18:05:25 by bedavis          ###   ########.fr       */
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

void parse_opt(t_printf *p)
{
	int w; //width
	int pres; //precision

	w = 1;
	pres = 1;
	if (ft_strchr("%#0-+ ", *p->format) != NULL)
	{
		p->flag = *p->format;
		p->format++;
	}
	if ((*p->format > '0') && (*p->format <= '9'))
	{
		w = ft_atoi(p->format) > 1 ? ft_atoi(p->format) : 1;
		while ((*p->format >= '0') && (*p->format <= '9'))
			++p->format;
	}
	if (*p->format++ == '.')
	{
		pres = ft_atoi(p->format) > 1 ? ft_atoi(p->format) : 1;
		while ((*p->format >= '0') && (*p->format <= '9'))
			++p->format;
	}
	//add here size and type parsing
}

void		parse(t_printf *p)
{
	size_t 	i;
	char 	*flags[4];
	int 	(*builtin_func[4]) (t_printf *p);

	i = 0;
	init_flags(flags);
	init_flag_func(builtin_func);
	parse_opt(p);
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

