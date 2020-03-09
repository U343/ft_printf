/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:16:00 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/17 16:12:13 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char *str, char c)
{
	size_t		count;
	size_t		flag;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str == c)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static void		ft_freew(char **words, size_t i)
{
	while (i--)
		ft_strdel(&words[i]);
	free(*words);
}

static char		*get_word(char *str, char c)
{
	char		*ss;

	ss = str;
	while (*str && *str != c)
	{
		str++;
	}
	*str = '\0';
	return (ft_strdup(ss));
}

static char		**get_words(char *str, char c, size_t count)
{
	char		**words;
	char		*word;
	size_t		i;

	i = 0;
	if ((words = (char **)malloc(sizeof(char *) * (count + 1))))
	{
		while (i < count)
		{
			while (*str == c)
				str++;
			if (*str)
			{
				if (!(word = get_word(str, c)))
				{
					ft_freew(words, i);
					return (NULL);
				}
				words[i++] = word;
				str += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char		*str;
	char		**result;

	if (!s || !(str = ft_strdup(s)))
		return (NULL);
	result = get_words(str, c, words_count(str, c));
	free(str);
	return (result);
}
