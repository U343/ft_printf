/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:52:34 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/13 18:57:21 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*head;
	size_t	i;

	if (s && f)
	{
		if (!(new = (char *)malloc(sizeof(char) * (1 + ft_strlen(s)))))
			return (NULL);
		head = new;
		i = 0;
		while (*s)
		{
			*new = f(i++, *s);
			s++;
			new++;
		}
		*new = '\0';
		return (head);
	}
	else
		return (NULL);
}
