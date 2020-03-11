#include <stdio.h>
#include "printf.h"

int main(void)
{
	//char *str = "User";
	printf("------------printf-----------------\n");
	printf("Hello, %-55.3s!\n", "abcd");
	printf("------------ft_printf--------------\n");
	ft_printf("Hello, %-55.3hs!\n", "abcd");
	printf("-----------------------------------\n");
	return (0);	
}
