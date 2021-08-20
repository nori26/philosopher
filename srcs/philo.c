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
	**philo = (t_phi){
		.format[0] = YELLOW"%ld %*ld has taken a fork\n"RESET,
		.format[1] = GREEN"%ld %*ld is eating\n"RESET,
		.format[2] = CYAN"%ld %*ld is sleeping\n"RESET,
		.format[3] = "%ld %*ld is thinking\n",
		.format[4] = RED"%ld %*ld died\n"RESET
	};
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
	philo->width = count_digits(philo->num_of_phi);
	return (0);
}

int	create_threads(t_data **data, t_phi *philo)
{
	int64_t	i;

	*data = malloc(sizeof(t_data) * philo->num_of_phi);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_of_phi);
	if (!*data || !philo->forks)
		return (1);
	mutex_init_forks(philo);
	i = 0;
	while (i < philo->num_of_phi)
	{
		(*data)[i] = (t_data){.phi = philo, .num = i + 1, .start = get_msec()};
		pthread_mutex_init(&(*data)[i].mstart, NULL);
		pthread_mutex_init(&(*data)[i].mdied, NULL);
		if (pthread_create(&(*data)[i].th, NULL, start_philo, &(*data)[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < philo->num_of_phi)
		if (pthread_join((*data)[i].th, NULL))
			return (1);
	return (0);
}

void	mutex_init_forks(t_phi *philo)
{
	int64_t	i;

	pthread_mutex_init(&philo->eos, NULL);
	i = 0;
	while (i < philo->num_of_phi)
		pthread_mutex_init(&philo->forks[i++], NULL);
}
