#include "libftprintf.h"

int main(void)
{
	int result;
	result = ft_printf("%%\n");
	printf("%d\n", result);
	return (0);
}