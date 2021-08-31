#include "philo.h"

int	create_threads(t_data *data, t_phi *philo)
{
	int64_t	i;
	t_func	run_simulation;

	i = 0;
	mtx_init_philo(philo);
	run_simulation = select_simulation(philo);
	while (i < philo->num_of_phi)
	{
		data_init(&data[i], i, philo);
		if (pthread_create(&data[i].thp, NULL, run_simulation, &data[i])
			|| pthread_create(&data[i].thd, NULL, doctor, &data[i]))
			return (1);
		i++;
	}
	return (0);
}

t_func	select_simulation(t_phi *philo)
{
	return ((t_func[2]){philosopher, nop}[philo->num_of_phi == 1]);
}

void	data_init(t_data *data, int64_t idx, t_phi *philo)
{
	*data = (t_data){
		.phi = philo,
		.num = idx + 1,
		.start = get_msec(),
	};
}

int	wait_end_of_simulation(t_data *data, t_phi *philo)
{
	int64_t	i;

	i = 0;
	while (i < philo->num_of_phi)
	{
		if (pthread_join(data[i].thd, NULL) || pthread_join(data[i].thp, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < philo->num_of_phi)
		pthread_mutex_destroy(&philo->forks[i++]);
	pthread_mutex_destroy(&philo->output);
	return (0);
}
