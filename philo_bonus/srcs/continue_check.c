#include "philo_bonus.h"

int64_t	continue_simulation(t_phi *philo)
{
	return (sem_do_func(philo, philo->outer, continue_inner));
}

int64_t	continue_inner(t_phi *philo)
{
	return (sem_do_func(philo, philo->inner, continue_check));
}

int64_t	continue_check(t_phi *philo)
{
	return (!philo->end);
}
