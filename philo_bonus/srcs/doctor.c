#include "philo_bonus.h"

void	*doctor(void *arg)
{
	t_phi	*philo;

	philo = arg;
	while (continue_simulation(philo))
	{
		philo->now = get_msec();
		if (over_deadline(philo))
			break ;
		usleep(1000);
	}
	return (NULL);
}
