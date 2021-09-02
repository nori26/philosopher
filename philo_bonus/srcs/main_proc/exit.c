#include "philo_bonus.h"

void	err_exit(t_phi *philo, char *message)
{
	free(philo);
	write(2, message, ft_strlen(message));
	kill(0, SIGINT);
}

void	free_exit(t_phi *philo, int status)
{
	free(philo);
	exit(status);
}
