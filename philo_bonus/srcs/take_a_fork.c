#include "philo_bonus.h"

void	get_forks(t_phi *philo)
{
	sem_wait(philo->forks1);
	take_a_fork(philo);
	sem_wait(philo->forks2);
	take_a_fork(philo);
}

void	release_forks(t_phi *philo)
{
	sem_post(philo->forks1);
	sem_post(philo->forks2);
}

void	take_a_fork(t_phi *philo)
{
	actions(philo, FORK, 0);
}
