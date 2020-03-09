/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:54:19 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/14 15:55:43 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dd;
	unsigned char *ss;

	dd = (unsigned char *)dst;
	ss = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dd < ss)
	{
		while (len--)
			*dd++ = *ss++;
	}
	else
	{
		dd = dd + len;
		ss = ss + len;
		while (len--)
		{
			dd--;
			ss--;
			*dd = *ss;
		}
	}
	return (dst);
}
