/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:28:24 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/06 23:34:14 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ss;
	unsigned char cc;

	ss = (unsigned char *)s;
	cc = (unsigned char)c;
	while (n--)
	{
		if (*ss == cc)
			return (ss);
		ss++;
	}
	return (NULL);
}
