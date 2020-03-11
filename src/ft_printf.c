/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:40:03 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/11 14:49:40 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_printf(const char *format, ...)
{
	t_printf p;

	ft_bzero(&p, sizeof(p));
	p.fd = 1;
	p.format = (char *)format;
	va_start(p.ap, format);
	while (*p.format)
	{
		if (*p.format == '%')
		{
			++p.format;
			if (!*p.format)
				break ;
			parse(&p);
		}
		else
			buffer(&p, p.format, 1);
		++p.format;
	}
	write(p.fd, p.buff, p.buffer_index);
	va_end(p.ap);
	return (p.len);
}

void	buffer(t_printf *p, void *new, size_t size)
{
	int			diff;
	long long	new_i;

	new_i = 0;
	while (BUF_SIZE - p->buffer_index < (int)size)
	{
		diff = BUF_SIZE - p->buffer_index;
		ft_memcpy(&(p->buff[p->buffer_index]), &(new[new_i]), diff);
		size -= diff;
		new_i += diff;
		p->buffer_index += diff;
		p->len += diff;
		write(p->fd, p->buff, p->buffer_index);
		p->buffer_index = 0;
	}
	ft_memcpy(&(p->buff[p->buffer_index]), &(new[new_i]), size);
	p->buffer_index += size;
	p->len += size;
}