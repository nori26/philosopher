#include "philo.h"

int	end_of_simulation(t_data *data, t_phi *philo)
{
	int	ret;

	ret = wait_threads(data, philo);
	mtx_destroy(philo);
	return (ret);
}

int	wait_threads(t_data *data, t_phi *philo)
{
	int64_t	i;

	i = 0;
	while (i < philo->num_of_phi)
	{
		if (pthread_join(data[i].thd, NULL) || pthread_join(data[i].thp, NULL))
			return (1);
		i++;
	}
	return (0);
}

void	mtx_destroy(t_phi *philo)
{
	int64_t	i;

	i = 0;
	while (i < philo->num_of_phi)
		pthread_mutex_destroy(&philo->forks[i++]);
	pthread_mutex_destroy(&philo->output);
}

void	exit_philo(t_data *data, t_phi *philo)
{
	if (philo)
		free(philo->forks);
	free(philo);
	free(data);
}
