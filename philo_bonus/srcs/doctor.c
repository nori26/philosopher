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

int64_t	over_deadline(t_phi *philo)
{
	return (sem_do_func(philo, &philo->outer, check_deadline));
}

int64_t	check_deadline(t_phi *philo)
{
	if (philo->deadline < philo->now - philo->start)//
	{
		died_notice(philo);
		return (1);
	}
	return (0);
}

int64_t	died_notice(t_phi *philo)
{
	print(&(t_print){philo, DIE});
	philo->dead = 1;
	return (0);
}
