#include <stdlib.h>
#include <errno.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdint.h>

int	main(void)
{
	int32_t	i = -10,
	j = 0,
	k = 0;

	(void)k;
	if (i >> 31)
		puts("OK");
	i /= j;
}
