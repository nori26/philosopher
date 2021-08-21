#include "philo.h"

int	main(int argc, char **argv)
{
	t_phi	*philo;
	t_data	*data;

	philo = NULL;
	data = NULL;
	if ((argc != 5 && argc != 6)
		|| philo_init(&philo)
		|| validate_args(argc, argv, philo)
		|| philo_utils_init(&data, philo)
		|| create_threads(data, philo)
		|| wait_end_of_simulation(data))
	{
		exit_philo(data, philo);
		return (1);
	}
	exit_philo(data, philo);
}

int	wait_end_of_simulation(t_data *data)
{
	int64_t	i;

	i = 0;
	while (i < data->phi->num_of_phi)
		if (pthread_join(data[i].th, NULL) || pthread_join(data[i++].th2, NULL))
			return (1);
	return (0);
}
