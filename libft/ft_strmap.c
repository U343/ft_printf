/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:14:20 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/13 17:00:43 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *new;
	char *head;

	if (s && f)
	{
		if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		head = new;
		while (*s)
		{
			*new = f(*s);
			s++;
			new++;
		}
		*new = '\0';
		return (head);
	}
	else
		return (NULL);
}
