/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:38:55 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/07 14:53:05 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	size;
	char	*dest;
	char	*src;

	dest = (char *)s1;
	src = (char *)s2;
	i = 0;
	size = 0;
	while (dest && dest[size] != '\0')
		size++;
	while (src[i] && src[i] != '\0' && i < n)
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}
