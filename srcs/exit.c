#include "philo.h"

void	exit_philo(t_data *data, t_phi *philo)
{
	free(philo);
	free(data);
}
