/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:40:32 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/14 18:13:54 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *t;

	if ((t = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (content)
		{
			if (!(t->content = ft_memalloc(content_size)))
			{
				free(t);
				return (NULL);
			}
			ft_memcpy(t->content, content, content_size);
			t->content_size = (size_t)content_size;
		}
		else
		{
			t->content = NULL;
			t->content_size = 0;
		}
		t->next = NULL;
	}
	return (t);
}
