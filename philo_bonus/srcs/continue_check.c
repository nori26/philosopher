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

// int64_t	alive_and_hungry(t_phi *philo)
// {
// 	return (is_alive(philo) && is_hungry(philo));
// }

// int64_t	is_hungry(t_phi *philo)
// {
// 	return (philo->musteat == -1
// 		|| philo->enough != philo->num_of_phi);
// }

// int64_t	is_alive(t_phi *philo)
// {
// 	return (!philo->dead);
// }
