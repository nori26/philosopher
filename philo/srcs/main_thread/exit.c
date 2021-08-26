#include "philo.h"

void	exit_philo(t_data *data, t_phi *philo)
{
	if (philo)
		free(philo->forks);
	free(philo);
	free(data);
	//pthread_mutex_destroy
}
