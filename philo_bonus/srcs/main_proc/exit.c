#include "philo_bonus.h"

void	exit_philo(t_phi *philo)
{
	if (philo)
		free(philo->pid);
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
	exit_philo(philo);
	exit(status);
}
