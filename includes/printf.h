/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:37:53 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/11 12:07:08 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include "libft.h"

#define BUF_SIZE		64

typedef struct			s_printf
{
	int					len;
	int					fd;
	int					buffer_index;
	char				buff[BUF_SIZE];
	va_list				ap;
	char				*format;
	char				flag;
	int					w;
	int					prec;
	char				*size;
	char				type;
}						t_printf;

/*
**----------------------------------Functions-----------------------------------
*/

int						ft_printf(const char *format, ...);
void					buffer(t_printf *p, void *new, size_t size);
void					parse(t_printf *p);


/*
**Flag functions
*/

int					s_flag(t_printf *p/*, int w, int pres*/);
int					d_flag(t_printf *p/*, int w, int pres*/);

#endif
