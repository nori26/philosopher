#include "philo.h"

void	exit_philo(t_data *data, t_phi *philo)
{
	if (philo)
		free(philo->fork);
	free(philo);
	free(data);
}
