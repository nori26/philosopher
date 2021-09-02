#include "philo_bonus.h"

void	exit_philo(t_phi *philo)
{
	if (philo)
		free(philo->pid);
	sem_end(philo->forks1, "/forks1");
	sem_end(philo->forks2, "/forks2");
	sem_end(philo->outer, "/outer");
	sem_end(philo->inner, "/inner");
	sem_end(philo->stop, "/stop");
	sem_end(philo->restart, "/restart");
	sem_end(philo->end_ready, "/end_ready");
	sem_end(philo->died, "/died");
	free(philo);
}

void	err_exit(t_phi *philo, char *message)
{
	exit_philo(philo);
	write(2, message, ft_strlen(message));
	kill(0, SIGINT);
}

void	free_exit(t_phi *philo, int status)
{
	free(philo->pid);
	free(philo);
	exit(status);
}
