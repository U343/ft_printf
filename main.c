#include <stdio.h>
#include "printf.h"

int main(void)
{
	char *str = "User";
	printf("------------printf-----------------\n");
	printf("Hello, %s!\n", str);
	printf("------------ft_printf--------------\n");
	ft_printf("Hello, %s!\n", str);
	printf("-----------------------------------\n");
	return (0);	
}
