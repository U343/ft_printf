/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:07:21 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/09 20:28:04 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (1);
		else
			return (0);
	}
	while (n && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		n--;
	}
	if (n)
		if (*s1 == *s2)
			return (1);
		else
			return (0);
	else
		return (1);
}
