/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:08:33 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/16 16:34:32 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*head;

	if (s1 && s2)
	{
		new = (char *)malloc(sizeof(char) *
				(ft_strlen(s1) + ft_strlen(s2) + 1));
		head = new;
		if (!new)
			return (NULL);
		while (*s1)
			*new++ = *s1++;
		while (*s2)
			*new++ = *s2++;
		*new = '\0';
		return (head);
	}
	return (NULL);
}
