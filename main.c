/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:18:14 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/11 13:36:06 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	long long	n=4444444444444441;
	printf("------------------\n");
	printf("num = %-04dF\n", 4);
	printf("My:\n");
	ft_printf("num = %dF\n", 4);
	return (0);
}