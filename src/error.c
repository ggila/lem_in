#include <stdlib.h>
#include "ft_printf.h"

void	error(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}
