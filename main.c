/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:18:14 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/09 16:00:12 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main(void)
{
	printf("------------------\n");
	printf("Hello, World!    num = %+d\n", 55);
	printf("My:\n");
	ft_printf("Hello, %s!\nIt's %d!!\n%s...", "WORLD", 4, "but");
	return (0);
}