#include "philo_bonus.h"

void	*philosopher(void *arg)
{
	delay_if_even(arg);
	while (continue_simulation(arg))
	{
		get_forks(arg);
		eating(arg);
		release_forks(arg);
		sleeping(arg);
		thinking(arg);
	}
	return (NULL);
}

void	*phisolopher(void *arg)
{
	take_a_fork(arg);
	return (arg);
}
