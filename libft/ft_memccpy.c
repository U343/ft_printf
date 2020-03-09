/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:30:09 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/14 16:06:39 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dd;
	unsigned char *ss;
	unsigned char cc;

	dd = (unsigned char*)dst;
	ss = (unsigned char *)src;
	cc = (unsigned char)c;
	if (n == 0)
		return (0);
	while (n--)
	{
		*dd = *ss;
		if (*dd == cc)
		{
			dd++;
			return (dd);
		}
		dd++;
		ss++;
	}
	return (NULL);
}
