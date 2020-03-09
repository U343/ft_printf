/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:18:14 by bedavis           #+#    #+#             */
/*   Updated: 2020/03/09 14:15:54 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main(void)
{
	printf("------------------\n");
	printf("Printf:\n");
	printf("Hello, World!\n");
	printf("My:\n");
	ft_printf("Hello, %s!\n", "World");
	return (0);
}