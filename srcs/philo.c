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
		|| create_threads(&data, philo)
		|| 0)
	{
		exit_philo(data, philo);
		return (1);
	}
	exit_philo(data, philo);
}

int32_t	philo_init(t_phi **philo)
{
	*philo = malloc(sizeof(t_phi));
	if (!*philo)
		return (1);
	**philo = (t_phi){};
	return (0);
}

int32_t	validate_args(int argc, char **argv, t_phi *philo)
{
	if (ft_atol_err(argv[1], &philo->num_of_phi)
		|| ft_atol_err(argv[2], &philo->deadline)
		|| ft_atol_err(argv[3], &philo->eat)
		|| ft_atol_err(argv[4], &philo->sleep)
		|| (argc == 6 && ft_atol_err(argv[5], &philo->times))
		|| philo->num_of_phi < 0
		|| philo->deadline < 0
		|| philo->eat < 0
		|| philo->sleep < 0
		|| philo->times < 0)
		return (1);
	printf("%ld %ld %ld %ld %ld\n", philo->num_of_phi, philo->deadline, philo->eat, philo->sleep, philo->times);
	philo->format[0] = "%ld %3ld has taken a fork\n";
	philo->format[1] = "%ld %3ld is eating\n";
	philo->format[2] = "%ld %3ld is sleeping\n";
	philo->format[3] = "%ld %3ld is thinking\n";
	philo->format[4] = "%ld %3ld died\n";
	return (0);
}

int	create_threads(t_data **data, t_phi *philo)
{
	int64_t	i;

	*data = malloc(sizeof(t_data) * philo->num_of_phi);
	philo->forks = malloc(philo->num_of_phi);
	if (!*data || !philo->forks)
		return (1);
	i = 0;
	while (i < philo->num_of_phi)
	{
		(*data)[i] = (t_data){.phi = philo, .num = i + 1};
		pthread_mutex_init(&philo->forks[i], NULL);
		if (pthread_create(&(*data)[i].th, NULL, start_philo, &(*data)[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < philo->num_of_phi)
		if (pthread_join((*data)[i].th, NULL))
			return (1);
	i = 0;
	while (i < philo->num_of_phi)
		printf("%ld\n", (*data)[i++].th);
	return (0);
}
