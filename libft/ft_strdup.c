/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:14:42 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/17 18:44:51 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	length;
	size_t	i;
	char	*res;

	i = 0;
	length = 0;
	while (s1[length] != '\0')
	{
		length++;
	}
	res = (char*)malloc(sizeof(char) * length + 1);
	if (res == (void *)0)
		return (res);
	while (s1 && s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
