#include "philo_bonus.h"

void	wait_ready_post_inner(t_phi *philo)
{
	sem_wait(philo->end_ready);
	sem_post(philo->inner);
}

void	wait_restart(t_phi *philo)
{
	sem_wait(philo->restart);
}

void	post_stop(t_phi *philo)
{
	sem_post(philo->stop);
}
