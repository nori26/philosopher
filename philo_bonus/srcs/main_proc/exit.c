#include "philo_bonus.h"

void	exit_philo(t_phi *philo)
{
	if (philo)
		free(philo->pid);
	sem_end(philo->forks1, "/forks1");
	sem_end(philo->forks2, "/forks2");
	sem_end(philo->outer, "/outer");
	sem_end(philo->musteat, "/musteat");
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
