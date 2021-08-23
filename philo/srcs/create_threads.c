#include "philo.h"

int	create_threads(t_data *data, t_phi *philo)
{
	int64_t	i;
	t_func	run_simulation;

	i = 0;
	run_simulation = select_simulation(philo);
	while (i < philo->num_of_phi)
	{
		data_init(&data[i], i, philo);
		if (pthread_create(&data[i].th, NULL, doctor, &data[i])
			|| pthread_create(&data[i].th2, NULL, run_simulation, &data[i]))
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
		.eatmax = philo->times
	};
	mtx_init_data(data);
}

void	mtx_init_data(t_data *data)
{
	pthread_mutex_init(&data->mtxstart, NULL);
	pthread_mutex_init(&data->mtxeatcount, NULL);
	pthread_mutex_init(&data->mtxnum, NULL);
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
