/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:55:16 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/17 13:11:47 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	init_flags(char *f[11])
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
	f[10] = NULL;
}

static void	init_flag_func(int (*b[11]) (t_printf *p))
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
	b[10] = NULL;
}

void init_struct(t_printf *p)
{
	p->bit = 0;
	p->w = 1;
	p->is_w = 0;
	p->prec = -1;
	p->size = "";
	p->type = 0;
}

void parse_size(t_printf *p)
{

	if (*p->format == 'l')
	{
		if (p->format[1] == 'l' && ++p->format)
		{
			p->bit |= 1 << 7;
			p->format++;
		}
		else {
			p->bit |= 1 << 6;
			p->format++;
		}
	}
	else if (*p->format == 'h')
	{
		if (p->format[1] == 'h' && ++p->format) {
			p->bit |= 1 << 9;
			p->format++;
		} else {
			p->bit |= 1 << 8;
			p->format++;
		}
	}
}

void parse_opt(t_printf *p)
{
	p->size = ft_strnew(3);
	while (ft_strchr(" #0-+", *p->format) != NULL)
	{
		p->bit |= 1 << ft_strpos(" #0-+", *p->format);
		p->format++;
	}
	if ((*p->format > '0') && (*p->format <= '9'))
	{
		p->w = ft_atoi(p->format) > 1 ? ft_atoi(p->format) : 1;
		if (p->w != 1)
			p->is_w = 1;
		while ((*p->format >= '0') && (*p->format <= '9'))
			++p->format;
	}
	if (*p->format == '.')
	{
		p->format++;
		p->prec = ft_atoi(p->format) > 1 ? ft_atoi(p->format) : 0;
		while ((*p->format >= '0') && (*p->format <= '9'))
			++p->format;
	}
	//size and type parsing
	parse_size(p);
	if (ft_strchr("cspdiouxX%", *p->format) != NULL)
		p->type = *p->format;
	else
		p->type = 0;
}

void		parse(t_printf *p)
{
	size_t 	i;
	char 	*flags[11];
	int 	(*builtin_func[11]) (t_printf *p);

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
