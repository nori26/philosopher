#include "libph.h"

void	philo_iterator(void *philo, int64_t n, void (*func)())
{
	int64_t	i;

	i = 0;
	while (i < n)
	{
		func(philo);
		i++;
	}
}
