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
