/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:24:26 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/14 16:06:14 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dd;
	unsigned char *ss;

	if (src == dst)
		return (dst);
	dd = (unsigned char*)dst;
	ss = (unsigned char *)src;
	while (n--)
	{
		*dd = *ss;
		dd++;
		ss++;
	}
	return (dst);
}
