/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:55:16 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/11 15:15:55 by wanton           ###   ########.fr       */
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

void init_struct(t_printf *p)
{
	p->flag[0] = 0;
	p->w = 1;
	p->prec = -1;
	p->size = NULL;
	p->type = 0;
}

void parse_size(t_printf *p)
{
	p->size = ft_strnew(2);
	if (*p->format == 'l')
	{
		if (p->format[1] == 'l' && ++p->format)
		{
			ft_strcpy(p->size, "ll");
			p->format+=2;
		}
		else {
			p->size[0] = 'l';
			p->format++;
		}
	}
	else if (*p->format == 'h')
	{
		if (p->format[1] == 'h' && ++p->format) {
			ft_strcpy(p->size, "hh");
			p->format += 2;
		} else {
			p->size[0] = 'h';
			p->format++;
		}
	}
}

void parse_opt(t_printf *p)
{
	if (ft_strchr("%#0-+ ", *p->format) != NULL)
	{
		p->flag[0] = *p->format;
		p->format++;
	}
	if ((*p->format > '0') && (*p->format <= '9'))
	{
		p->w = ft_atoi(p->format) > 1 ? ft_atoi(p->format) : 1;
		while ((*p->format >= '0') && (*p->format <= '9'))
			++p->format;
	}
	if (*p->format++ == '.')
	{
		p->prec = ft_atoi(p->format) > 1 ? ft_atoi(p->format) : 1;
		//p->format++;
		while ((*p->format >= '0') && (*p->format <= '9'))
			++p->format;
	}
	//size and type parsing
	parse_size(p);
	if (ft_strchr("cspdiouxX", *p->format) != NULL)
		p->type = *p->format;
	else
		p->type = 0;
}

void		parse(t_printf *p)
{
	size_t 	i;
	char 	*flags[4];
	int 	(*builtin_func[4]) (t_printf *p);

	i = 0;
	init_flags(flags);
	init_flag_func(builtin_func);
	init_struct(p);
	parse_opt(p);
	while (flags[i])
	{
		if ((ft_strncmp(&p->type, flags[i], ft_strlen(flags[i])) == 0))
		{
			(*builtin_func[i])(p);
			//p->format += (ft_strlen(flags[i]) - 1);
			break;
		}
		i++;
	}
}

