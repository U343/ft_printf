/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:37:53 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/17 14:27:01 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h> // delete
#include "../libft/includes/libft.h"

#define BUF_SIZE		64
// Check ft_printf format flags
# define FL_SPACE		(1 << 0)
# define FL_SHARP		(1 << 1)
# define FL_ZERO		(1 << 2)
# define FL_MINUS		(1 << 3)
# define FL_PLUS		(1 << 4)
// Check number format:
# define FL_L			(1 << 6)
# define FL_LL			(1 << 7)
# define FL_H			(1 << 8)
# define FL_HH			(1 << 9)

# define NUM_MINUS		(1 << 10) // check minus of the input value
# define CHECK_P		(1 << 11) // Показывает напетаны ли символы +/-
# define CHECK_U		(1 << 12) // Показывает напечатаны ли префиксы #
# define ZERO_VALUE     (1 << 13) // Проверка на нулевое значение
# define FL_BIGL        (1 << 15) // shows 'L'

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
	int                 lenofprint;
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
void					res_to_buff(char *s, t_printf *p);


/*
**Flag functions
*/

int						s_flag(t_printf *p);
int						d_flag(t_printf *p);
int						c_flag(t_printf *p);
int						pr_flag(t_printf *p);
int						p_flag(t_printf *p);
int						f_flag(t_printf *p);

/*
**Init functions
*/

void					init_flags(char *f[12]);
void					init_flag_func(int (*b[12]) (t_printf *p));
void					init_struct(t_printf *p);

/*
**Functions for d_flag
*/

int						check_first_space(t_printf *p, int size);
char					*width_symbol(t_printf *p);
char 					*check_znak(long long value,
		t_printf *p, int base, int format);
void					calculating_width(t_printf *p);
void					take_symbol(t_printf *p);
int                     p_one(int a);

#endif
