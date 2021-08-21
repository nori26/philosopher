#include "philo.h"

void	*start_philo(void *arg)
{
	forks_init(arg);
	while (!is_dead(arg))
	{
		get_forks(arg);
		eating(arg);
		release_forks(arg);
		sleeping(arg);
		thinking(arg);
	}
	return (NULL);
}
