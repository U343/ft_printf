/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:21:06 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/07 14:50:37 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char	*dest;
	char	*src;
	size_t	i;
	size_t	size;

	dest = (char *)s1;
	src = (char *)s2;
	i = 0;
	size = 0;
	while (dest && dest[size] != '\0')
		size++;
	while (src[i] && src[i] != '\0')
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}
