/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:59:25 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/17 15:56:53 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	strt;
	size_t	fin;
	char	*new;
	size_t	i;

	if (s != NULL)
	{
		fin = ft_strlen(s);
		strt = 0;
		i = 0;
		while ((ft_isspace(s[strt]) || (s[strt] == '\n')) && s[strt])
			strt++;
		while ((ft_isspace(s[fin - 1]) || (s[fin - 1] == '\n')) && (fin > strt))
			fin--;
		if ((new = ft_strnew(fin - strt)))
		{
			while (strt < fin)
			{
				new[i++] = s[strt++];
			}
			new[i] = '\0';
			return (new);
		}
	}
	return (NULL);
}
