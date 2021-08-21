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
		|| wait_end(data))
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
		.format[4] = RED"%ld %*ld died\n"RESET,
		.times = -1
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
		|| (argc == 6 && philo->times < 0))
		return (1);
	return (0);
}

int	philo_utils_init(t_data **data, t_phi *philo)
{
	*data = malloc(sizeof(t_data) * philo->num_of_phi);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_of_phi);
	if (!*data || !philo->forks)
		return (1);
	mtx_init_philo(philo);
	philo->width = count_digits(philo->num_of_phi);
	return (0);
}

int	create_threads(t_data *data, t_phi *philo)
{
	int64_t		i;

	// philo->width = count_digits(philo->num_of_phi);
	// *data = malloc(sizeof(t_data) * philo->num_of_phi);
	// philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_of_phi);
	// if (!*data || !philo->forks)
	// 	return (1);
	// mtx_init_philo(philo);
	i = 0;
	while (i < philo->num_of_phi)
	{
		data_init(&data[i], i, philo);
		if (pthread_create(&data[i].th, NULL, doctor, &data[i])
			|| pthread_create(&data[i].th2, NULL, start_philo, &data[i]))
			return (1);
		i++;
	}
	return (0);
}
void	data_init(t_data *data, int64_t idx, t_phi *philo)
{
	*data = (t_data){
		.phi = philo,
		.num = idx + 1,
		.start = get_msec(),
		.eatmax = philo->times
	};
	mtx_init_data(data);
}

void	mtx_init_data(t_data *data)
{
	pthread_mutex_init(&data->mtxstart, NULL);
	pthread_mutex_init(&data->mtxdied, NULL);
	pthread_mutex_init(&data->mtxeatcount, NULL);
}

int	wait_end(t_data *data)
{
	int64_t	i;

	i = 0;
	while (i < data->phi->num_of_phi)
		if (pthread_join(data[i].th, NULL) || pthread_join(data[i++].th2, NULL))
			return (1);
	return (0);
}

void	mtx_init_philo(t_phi *philo)
{
	int64_t	i;

	pthread_mutex_init(&philo->eos, NULL);
	pthread_mutex_init(&philo->output, NULL);
	i = 0;
	while (i < philo->num_of_phi)
		pthread_mutex_init(&philo->forks[i++], NULL);
}
