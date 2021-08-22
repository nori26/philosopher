#include "philo.h"

void	*start_philo(void *arg)
{
	if (((t_data *)arg)->phi->num_of_phi == 1)
		return (NULL);
	forks_init(arg);
	while (is_living(arg) && is_hungry(arg))
	{
		get_forks(arg);
		eating(arg);
		release_forks(arg);
		sleeping(arg);
		thinking(arg);
	}
	return (NULL);
}
