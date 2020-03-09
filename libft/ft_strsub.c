/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:46:20 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/17 18:15:27 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	end;
	char	*new;

	if (s && (len < (len + 1)) && ((ft_strlen(s) + 1) >= (len + start)))
	{
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (!new)
			return (NULL);
		i = 0;
		end = 0;
		while (i < len)
		{
			new[i++] = s[start];
			if (s[start] == '\0')
				end = 1;
			start++;
		}
		if (!end)
			new[i] = '\0';
		return (new);
	}
	return (NULL);
}
