/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:55:16 by bedavis           #+#    #+#             */
/*   Updated: 2020/05/21 16:13:53 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_size(t_printf *p)
{
	if (*p->format == 'l')
	{
		if (p->format[1] == 'l' && ++p->format)
		{
			p->bit |= 1 << 7;
			p->format++;
		}
		else
		{
			p->bit |= 1 << 6;
			p->format++;
		}
	}
	else if (*p->format == 'h' || *p->format == 'L')
		parse_size_continue(p);
}

void	parse_width(t_printf *p)
{
	int		spec;

	if (((*p->format > '0') && (*p->format <= '9')) || *p->format == '*')
	{
		p->is_w = 1;
		if (*p->format == '*')
		{
			++p->format;
			spec = va_arg(p->ap, int);
			if (!ft_isdigit(*p->format))
			{
				p->is_w = (spec == 0) ? 0 : 1;
				true_asterisk_width(p, spec);
				return ;
			}
		}
		p->w = ft_atoi(p->format) > 1 ? ft_atoi(p->format) : 1;
		while ((*p->format >= '0') && (*p->format <= '9'))
			++p->format;
	}
}

void	parse_prec(t_printf *p)
{
	int		prec;

	if (*p->format == '.')
	{
		p->format++;
		if (*p->format == '*')
		{
			prec = va_arg(p->ap, int);
			++p->format;
			if (!ft_isdigit(*p->format))
			{
				if (prec < 0)
					return ;
				p->prec = prec >= 1 ? prec : 0;
				return ;
			}
		}
		p->prec = ft_atoi(p->format) >= 1 ? ft_atoi(p->format) : 0;
		while ((*p->format >= '0') && (*p->format <= '9'))
			++p->format;
	}
}

void	parse_opt(t_printf *p)
{
	while (ft_strchr(" #0-+", *p->format) != NULL)
	{
		p->bit |= 1 << ft_strpos(" #0-+", *p->format);
		p->format++;
	}
	parse_width(p);
	parse_prec(p);
	parse_size(p);
	if (ft_strchr("cspdiouxXf%", *p->format) != NULL)
		p->type = *p->format;
	else
		p->type = 0;
}

void	parse(t_printf *p)
{
	size_t	i;
	char	*flags[12];
	int		(*builtin_func[12]) (t_printf *p);

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
			break ;
		}
		i++;
	}
}
