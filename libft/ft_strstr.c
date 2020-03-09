/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:16:04 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/14 16:14:20 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	str = (char*)haystack;
	to_find = (char*)needle;
	len = 0;
	i = -1;
	while (to_find[len])
		len++;
	if (len == 0)
		return (str);
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (j == (len - 1))
				return (str + i);
			j++;
		}
	}
	return (NULL);
}
