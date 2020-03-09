/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:03:06 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/17 15:46:29 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(void *content, size_t content_size)
{
	(void)content_size;
	if (!content)
		free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*t;
	t_list	*new;
	t_list	*head;

	head = NULL;
	if (lst && f)
	{
		t = lst;
		while (t)
		{
			if (!(new = f(t)))
			{
				if (head)
					ft_lstdel(&head, &ft_free);
				return (NULL);
			}
			ft_lstaddend(&head, new);
			t = t->next;
		}
	}
	return (head);
}
