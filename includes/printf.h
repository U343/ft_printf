/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:37:53 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/09 12:53:57 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLION_PRINTF_PRINTF_H
#define CLION_PRINTF_PRINTF_H

#include <stdarg.h>
#include "../libft/includes/libft.h"

#define BUF_SIZE		64

typedef struct			s_printf
{
	int					len;
	int					fd;
	int					buffer_index;
	char				buff[BUF_SIZE];
	va_list				ap;
	char				*format;
}						t_printf;

	int					ft_printf(const char *format, ...);
	void				buffer(t_printf *p, void *new, size_t size);
	void				parse(t_printf *p);

#endif
