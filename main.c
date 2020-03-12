

#include "printf.h"

int       main(void)
{
	long	n=4;
	printf("Hello\n");
	printf("------------------\n");
	printf("num = %+4liF\n", n);
	printf("My:\n");
	ft_printf("num = %+4liF\n", n);
	return (0);
}
