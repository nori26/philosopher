#include "philo.h"

int	freeturn(char **p, int ret)
{
	free(*p);
	*p = NULL;
	return (ret);
}
