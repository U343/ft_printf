/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:50:08 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/17 13:55:36 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	str = (char*)haystack;
	to_find = (char*)needle;
	i = 0;
	if (!(l = ft_strlen(to_find)) || (str == to_find))
		return (str);
	if (ft_strlen(str) < l || len < l)
		return (NULL);
	while (str && str[i] && i <= len - l)
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
			j++;
		if (j == l)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
