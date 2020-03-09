/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:54:51 by bedavis           #+#    #+#             */
/*   Updated: 2019/09/16 15:58:15 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *t;

	if (alst && *alst)
	{
		t = *alst;
		while (t->next)
			t = t->next;
		t->next = new;
	}
	else if (alst)
	{
		*alst = new;
	}
}
