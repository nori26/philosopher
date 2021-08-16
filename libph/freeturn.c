#include "philo.h"

int	freeturn(void *p, int ret)
{
	free(*(void **)p);
	*(void **)p = NULL;
	return (ret);
}
