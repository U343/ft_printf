/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:19:49 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/16 14:36:20 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst && *alst && del)
	{
		while (*alst)
		{
			temp = *alst;
			del((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(temp);
		}
		*alst = NULL;
	}
}
