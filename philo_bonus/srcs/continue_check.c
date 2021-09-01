#include "philo_bonus.h"

int64_t	continue_simulation(t_phi *philo)
{
	return (sem_do_func(philo, &philo->outer, alive_and_hungry));
}

int64_t	alive_and_hungry(t_phi *philo)
{
	return (is_alive(philo) && is_hungry(philo));
}

int64_t	is_hungry(t_phi *philo)
{
	return (philo->eatmax == -1
		|| philo->enough != philo->num_of_phi);
}

int64_t	is_alive(t_phi *philo)
{
	return (!philo->dead);
}
