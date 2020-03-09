/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:04:35 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/07 16:18:53 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*ss;
	char	cc;
	size_t	l;

	ss = (char *)s;
	cc = (char)c;
	l = ft_strlen(ss);
	ss = ss + l;
	if (cc == '\0')
		return (ss);
	while (ss >= s)
	{
		if (*ss == cc)
			return (ss);
		ss--;
	}
	return (NULL);
}
