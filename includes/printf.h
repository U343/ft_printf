/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:37:53 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/11 14:51:25 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h> // delete
#include "libft.h"

#define BUF_SIZE		64

# define FL_PERC		(1 << 0)
# define FL_SHARP		(1 << 1)
# define FL_ZERO		(1 << 2)
# define FL_MINUS		(1 << 3)
# define FL_PLUS		(1 << 4)
# define FL_SPACE		(1 << 5

# define FT_MIN(a, b)		(a < b) ? a : b
# define FT_MAX(a, b)		(a > b) ? a : b
# define FT_ABS(a)			(a < 0) ? -a : a
# define FT_DABS(a)			(a < 0.0f) ? -a : a

typedef struct			s_printf
{
	int					len;
	int 				w;
	int					is_w;
	int					fd;
	int					buffer_index;
	int 				prec;
	char				buff[BUF_SIZE];
	va_list				ap;
	char				*format;
	int					bit;
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

int					s_flag(t_printf *p);
int					d_flag(t_printf *p);
int					c_flag(t_printf *p);

#endif
