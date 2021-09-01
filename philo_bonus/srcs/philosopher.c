#include "philo_bonus.h"

void	philo_manager(t_phi *philo)
{
	create_threads(philo);
	notice_die_or_eat_enough(philo);
	wait_threads(philo);
}

int	create_threads(t_phi *philo)
{
	int64_t	i;
	t_func	run_simulation;

	i = 0;
	run_simulation = select_simulation(philo);
	while (i < philo->num_of_phi)
	{
		if (pthread_create(&philo->thp, NULL, run_simulation, &philo)
			|| pthread_create(&philo->thd, NULL, doctor, &philo))
			free_exit(philo, 1);
		i++;
	}
	return (0);
}

t_func	select_simulation(t_phi *philo)
{
	return ((t_func[2]){philosopher, phisolopher}[philo->num_of_phi == 1]);
}

void	notice_die_or_eat_enough(t_phi *philo)
{
	sem_wait(philo->stop);
	philo->end = 1;
	sem_post(philo->restart);
}

void	*philosopher(void *arg)
{}

void	*phisolopher(void *arg)
{
	take_a_fork(arg);
	return (arg);
}

void	wait_threads(t_phi *philo)
{
	if (pthread_join(philo->thd, NULL) || pthread_join(philo->thp, NULL))
		free_exit(philo, 1);
}

void	free_exit(t_phi *philo, int status)
{
	free(philo->pid);
	free(philo);
	exit(status);
}